#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <poll.h>
#include <errno.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/signalfd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/inotify.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/types.h>
#include <dirent.h>
#include <error.h>
#include <errno.h>
#include <sys/inotify.h>
#include <string>
#include <map>



#include "defenmodproxy.h"
#include "baseconfig.h"
#include "commonapi.h"
#include "panzer_if.h"
#include "observer.h"

//#define FANOTIFY_EXEC
#ifdef FANOTIFY_EXEC

#include <linux/fanotify.h>
#include <sys/fanotify.h>
/* Structure to keep track of monitored directories */
typedef struct {
  /* Path of the directory */
  char *path;
} monitored_t;

/* Size of buffer to use when reading fanotify events */
#define FANOTIFY_BUFFER_SIZE 8192

/* Setup fanotify notifications (FAN) mask. All these defined in fanotify.h. */
static uint64_t event_mask =
    (   FAN_ACCESS |         /* File accessed */
        FAN_MODIFY |         /* File modified */
        FAN_CLOSE_WRITE |    /* Writtable file closed */
        FAN_CLOSE_NOWRITE |  /* Unwrittable file closed */
        FAN_OPEN |           /* File was opened */
        FAN_ONDIR |          /* We want to be reported of events in the directory */
        FAN_EVENT_ON_CHILD
        //FAN_OPEN_PERM
        //| FAN_ACCESS_PERM
     ); /* We want to be reported of events in files of the directory */

/*
static char *get_program_cmdline_from_pid(int pid, char *buffer, size_t buffer_size) {
    int i;
    int fd;
    ssize_t len;

    // Try to get program name by PID
    sprintf(buffer, "/proc/%d/cmdline", pid);
    if ((fd = open(buffer, O_RDONLY)) < 0)
        return NULL;

    // Read file contents into buffer
    if ((len = read(fd, buffer, buffer_size - 1)) <= 0) {
        close(fd);
        printf("read the pid:%d cmd error\n", pid);
        return NULL;
    }
    close(fd);

    for (i = 0; i < len; i++) {
        if (buffer[i] == '\0') {
            buffer[i] = ' ';
        }
    }

    buffer[len] = '\0';

    return buffer;
}
*/

static char *get_file_path_from_fd(int fd, char *buffer, size_t buffer_size) {
    ssize_t len;

    if (fd <= 0)
        return NULL;

    sprintf(buffer, "/proc/self/fd/%d", fd);
    if ((len = readlink(buffer, buffer, buffer_size - 1)) < 0){
        perror("readlink");
        exit(EXIT_FAILURE);
    }

    buffer[len] = '\0';
    return buffer;
}

#endif

#define FILE_MONITOR_DELAY  2

const char *paths[] = {"/bin", "/usr/bin", "/usr/lib", "/boot"};
//const char *paths[] = {"/bin", "/home/lang/work_rising/file_monitor_test"};

DefenModProxy::DefenModProxy() {
    mStatus = 0;
    mObserver = NULL;
    mDefenceThread = 0;
}

DefenModProxy::~DefenModProxy() {
    Stop();
}

char *DefenModProxy::get_proc_path(int pid, char *path, int path_len) {
    int rslt;
    char link[100];

    sprintf(link, "/proc/%d/exe", pid);
    rslt = readlink(link, path, path_len - 1);
    if (rslt < 0 || rslt >= path_len - 1)
        return NULL;
    path[rslt] = '\0';
    return path;
}

int DefenModProxy::Start() {
    pthread_mutex_init(&mMutex, NULL);    
    return pthread_create(&mDefenceThread, NULL, DefenceWork, this);
}

int DefenModProxy::Stop() {
    mStatus = 0;

    if (mDefenceThread) {
        //pthread_cancel(mDefenceThread);
        pthread_join(mDefenceThread, NULL);
    }

    pthread_mutex_destroy(&mMutex);

    return 0;
}

void* DefenModProxy::DefenceWork(void *args) {
    DefenModProxy *self = (DefenModProxy*)args;
    self->DefenceWorkFunc();
    return NULL;
}


void DefenModProxy::InitAllWds(const char *pcName, bool bRecursion)
{
    int iWd;
    struct stat tStat;
    DIR *pDir;
    struct dirent *ptDirent;
    char caNametmp[4096]; // 存储目录名字

    //printf("add watch:%s, %d\n", pcName, miCount);
    if (-1 == lstat(pcName, &tStat)) {
        printf("stat %s error\n", pcName);
        return;
    }
    if (!S_ISDIR(tStat.st_mode))
        return;
    if(S_ISLNK(tStat.st_mode))
    {
        printf("pcName is symbolic link!\n");
        return;
    }

    if(miCount >= (MAX_FILES_MONITOR-1)){
        //printf("inotify_add_watch num:%d , add dir path:%s error!\n", miCount, pcName);
        return;
    }

    //printf("inotify_add_watch :%s !\n", pcName);
    iWd = inotify_add_watch(miNotifyFd, pcName, IN_ALL_EVENTS);
    miWds[miCount] = iWd;
    mFileDirMap[iWd] = pcName;
    miCount++;

    if(bRecursion)
        return;
    /* 处理子目录 */
    pDir = opendir(pcName);
    if (NULL == pDir) {
        printf("opendir %s error\n", pcName);
        return;
    }

    // 循环读目录下面的子项
    while (NULL != (ptDirent = readdir(pDir))) {
        if ((0 == strcmp(ptDirent->d_name, ".")) || (0 == strcmp(ptDirent->d_name, "..")))
            continue; // 跳过当前目录和上一级父目录

        if(strlen(pcName) + strlen(ptDirent->d_name) > 4096)
            break;
        sprintf(caNametmp, "%s/%s", pcName, ptDirent->d_name); //获取子目录或文件名字
        if (-1 == stat(caNametmp, &tStat)) {
            printf("stat error:%s\n", caNametmp); // 获取统计数据
            return;
        }
        if (!S_ISDIR(tStat.st_mode)) //看是否是子目录，原则只处理目录
            continue;

        InitAllWds(caNametmp); //处理子目录
    }

    // 关闭
    closedir(pDir);
}


int DefenModProxy::WatchInotifyEvents(int fd)
{
    char event_buf[512];
    int ret;
    int event_pos = 0;
    int event_size = 0;
    struct inotify_event *event;

    ret = read(miNotifyFd, event_buf, sizeof(event_buf));

    if (ret < (int)sizeof(struct inotify_event)) {
        printf("counld not get event!\n");
        return -1;
    }
    while (ret >= (int)sizeof(struct inotify_event)) {
        event = (struct inotify_event*)(event_buf + event_pos);
        if (event->len >0 ) {
            //printf("wd:%d, path:%s, name = %s\n", event->wd, mFileDirMap[event->wd].c_str(), event->name);
        }
        else
            break;

        string pathname=mFileDirMap[event->wd] +string("/") +  string(event->name);

        /*
        printf("mask = ");
        if (event->mask & IN_ACCESS)        printf("IN_ACCESS ");
        if (event->mask & IN_ATTRIB)        printf("IN_ATTRIB ");
        if (event->mask & IN_CLOSE_NOWRITE) printf("IN_CLOSE_NOWRITE ");
        if (event->mask & IN_CLOSE_WRITE)   printf("IN_CLOSE_WRITE ");
        if (event->mask & IN_CREATE)        printf("IN_CREATE ");
        if (event->mask & IN_DELETE)        printf("IN_DELETE ");
        if (event->mask & IN_DELETE_SELF)   printf("IN_DELETE_SELF ");
        if (event->mask & IN_IGNORED)       printf("IN_IGNORED ");



        if (event->mask & IN_MODIFY)        printf("IN_MODIFY ");
        if (event->mask & IN_MOVE_SELF)     printf("IN_MOVE_SELF ");
        if (event->mask & IN_MOVED_FROM)    printf("IN_MOVED_FROM ");
        if (event->mask & IN_MOVED_TO)      printf("IN_MOVED_TO ");
        if (event->mask & IN_OPEN)          printf("IN_OPEN ");
        if (event->mask & IN_Q_OVERFLOW)    printf("IN_Q_OVERFLOW ");
        if (event->mask & IN_UNMOUNT)       printf("IN_UNMOUNT ");
        */

        if (event->mask & IN_ISDIR) {

            //printf("IN_ISDIR ");
            InitAllWds(pathname.c_str());
        }

        if(event->mask & (IN_MODIFY))
        {

            //LOG_ZDFY("inotify_event file chmod %s", pathname.c_str());
            //printf("inotify_event file chmod %s\n", pathname.c_str());
            if (mObserver) {
                mObserver->onDefenEvent(DefenObserver::DEFEN_FILE_WRITE, pathname.c_str());
            }
        }

        //printf("\n");

        event_size = sizeof(struct inotify_event) + event->len;
        ret -= event_size;
        event_pos += event_size;
    }
    return 0;
}

int DefenModProxy::InitNotify(){
    /* inotify初始化 */
    miNotifyFd = inotify_init1(IN_NONBLOCK);
    if (miNotifyFd == -1) {
        printf("inotify_init error!\n");
        return -1;
    }

    list<string> &fl = mObserver->GetFolderMonitorList();
    printf("fl---------%ld\n", fl.size());

    for(list<string>::iterator it=fl.begin(); it!=fl.end(); it++)
    {
        string path, name;
        Utils::Path::SplitPath(*it, path, name);

        LOG_ZDFY("add InitNotify %s", path.c_str());
        InitAllWds(path.c_str(), true);
    }


    size_t lens = sizeof(paths)/ sizeof(char*);
    for(size_t i=0; i< lens; i++){
        LOG_ZDFY("add paths:%s add child dir", paths[i]);
        InitAllWds(paths[i]);
    }

    miFdsNum = 1;

    mFds[0].fd = miNotifyFd;
    mFds[0].events = POLLIN;

    printf("Listening for events.\n");

    mStatus = 1;

    return 0;
}

void DefenModProxy::DefenceWorkFunc() {

    int timeout = -1;
#ifdef FANOTIFY_EXEC
    InitializeFanotify();
#else
    InitNotify();
    timeout = 100;
#endif

    while (mStatus > 0) {
        //printf("mStatus fd = %d miFdsNum:%d, event!\n", mFds[0].fd, miFdsNum);
        int poll_num = poll(mFds, miFdsNum, timeout);

        //printf("poll fd event!\n");
        if (poll_num == -1) {
            if (errno == EINTR)
                continue;
            perror("poll");
            exit(EXIT_FAILURE);
        }

        if (poll_num > 0) {
            if (mFds[0].revents & POLLIN) {
                /* Inotify events are available */
#ifdef FANOTIFY_EXEC
                WatchFanotifyEvents(mFds[1].fd);
#else
                //printf("poll exec!\n");
                //LOG_ZDFY("poll exec");
                WatchInotifyEvents(mFds[1].fd);
#endif

            }
        }
    }

    printf("added watch iwds:%d, CountDefenceWorkFunc exit!\n", miCount);
#ifdef FANOTIFY_EXEC
    ShutdownFanotify(mFds[1].fd);
#else
     /* 删除inotify的watch对象 */
     for (int icount = 0; icount < miCount; icount++) {
        if (inotify_rm_watch(miNotifyFd, miWds[icount]) == -1) {
            printf("notify_rm_watch iwd[%d] = %d error!\n", icount, miWds[icount]);
            continue;
        }
     }

     //memset(miWds, 0, )
     close(miNotifyFd);
     //miWds[miCount] = iWd;
     mFileDirMap.clear();
     miCount=0;
     miNotifyFd = -1;
#endif
}

void* DefenModProxy::ThreadWriteCheck(void *args) {
    DefenModProxy *self = (DefenModProxy*)args;
    self->WriteCheckFunc();
    return NULL;
}

void DefenModProxy::WriteCheckFunc() {
    while(mStatus > 0) {
        pthread_mutex_lock(&mMutex);
        {
            long now = Utils::Date::GetTimeStamp();
            map<string, long>::iterator iter;
            for (iter=mWriteMap.begin();iter!=mWriteMap.end();++iter) {
                if (now - iter->second > FILE_MONITOR_DELAY) {
                    if (mObserver) {
                        mObserver->onDefenEvent(DefenObserver::DEFEN_FILE_WRITE, iter->first.c_str());
                    }
                    mWriteMap.erase(iter);
                    break;
                }
            }
        }
        pthread_mutex_unlock(&mMutex);

        sleep(FILE_MONITOR_DELAY);
    }
}

#ifdef FANOTIFY_EXEC
void DefenModProxy::WatchFanotifyEvents(int fd) {
    char buffer[FANOTIFY_BUFFER_SIZE];
    ssize_t length;

    /* Read from the FD. It will read all events available up to
     * the given buffer size. */
    if ((length = read(mFds[0].fd,
                       buffer,
                       FANOTIFY_BUFFER_SIZE)) > 0) {
        struct fanotify_event_metadata *event;

        event = (struct fanotify_event_metadata *) buffer;

        while (FAN_EVENT_OK (event, length)) {

        //printf("event_process ");
        if(mPid == event->pid){
             //printf("event_process self end!\n");

             close(event->fd);
             event = FAN_EVENT_NEXT (event, length);
             continue;
        }

        char path[PATH_MAX];
        char *buf_path = get_file_path_from_fd(event->fd, path, PATH_MAX);

        /*
        printf("%s [%d] Event on '%s' ",
               strtok(c_time_string, "\n"),
               event->pid,  buf_path ? path : "unknown");

        printf("event fd:%d: ", event->fd);
        if (event->mask & FAN_OPEN)
            printf("FAN_OPEN ");
        if (event->mask & FAN_ACCESS)
            printf("FAN_ACCESS ");
        if (event->mask & FAN_MODIFY)
            printf("FAN_MODIFY ");
        if (event->mask & FAN_CLOSE_WRITE)
            printf("FAN_CLOSE_WRITE ");
        if (event->mask & FAN_CLOSE_NOWRITE)
            printf("FAN_CLOSE_NOWRITE ");
        */
        if((event->mask & FAN_MODIFY) && buf_path)
        {

            //LOG_ZDFY("file chmod %s\n", path);
            if (mObserver) {
                mObserver->onDefenEvent(DefenObserver::DEFEN_FILE_WRITE, path);
            }
        }

        close(event->fd);
        event = FAN_EVENT_NEXT (event, length);
    }
    }else{
        LOG_ZDFY("error read(fds[FD_POLL_FANOTIFY].fd");
        return;
    }
}

void DefenModProxy::ShutdownFanotify(int fanotify_fd) {
    LOG_ZDFY("ShutdownFanotify fd %d", fanotify_fd);
    list<string> &fl = mObserver->GetFolderMonitorList();
    for(list<string>::iterator it=fl.begin(); it!=fl.end(); it++) {
        string path, name;
        Utils::Path::SplitPath(*it, path, name);

        if (fanotify_mark(miNotifyFd, FAN_MARK_REMOVE,
                          event_mask, AT_FDCWD, path.c_str()) < 0){
            LOG_ZDFY("error Couldn't ShutdownFanotify in directory '%s': '%s'", path.c_str(), strerror(errno));
            break;
        }
    }

    close(fanotify_fd);
    fanotify_fd = -1;
}

int DefenModProxy::InitializeFanotify() {
    mPid = getpid();
    if ((miNotifyFd = fanotify_init(FAN_CLOEXEC  | FAN_NONBLOCK | FAN_CLASS_NOTIF,
                                     O_RDONLY | O_LARGEFILE)) < 0)
    {
        LOG_ZDFY("error Couldn't setup new InitializeFanotify device: %s", strerror(errno));
        return -1;
    }

    list<string> &fl = mObserver->GetFolderMonitorList();
    for(list<string>::iterator it=fl.begin(); it!=fl.end(); it++) {
        string path, name;
        Utils::Path::SplitPath(*it, path, name);

        if (fanotify_mark(miNotifyFd, FAN_MARK_ADD | FAN_MARK_MOUNT,
                          event_mask, AT_FDCWD, path.c_str()) < 0){
            LOG_ZDFY("error Couldn't add monitor in directory '%s': '%s'", path.c_str(), strerror(errno));
            break;
        }
    }

    miFdsNum = 1;
    mFds[0].fd = miNotifyFd;
    mFds[0].events = POLLIN;
    mStatus = 1;

    return miNotifyFd;
}
#endif

