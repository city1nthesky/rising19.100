#ifndef DEFENMODPROXY_H
#define DEFENMODPROXY_H


#define MAX_FILES_MONITOR 4096


#include <pthread.h>
#include <poll.h>

#include <map>
#include <string>

using namespace std;

class DefenObserver;
class DefenModProxy
{
public:
    DefenModProxy();
    virtual ~DefenModProxy();

    void SetObserver(DefenObserver *observer) {
        mObserver = observer;
    }

    int Start();
    int Stop();

    int Status() const {
        return mStatus;
    }

private:

#ifdef FANOTIFY_EXEC

    __pid_t mPid;
    int InitializeFanotify();

    void WatchFanotifyEvents(int fd) ;
    void ShutdownFanotify(int fanotify_fd);

#endif

    int WatchInotifyEvents(int fd);

    //Recursion 是否递归处理子目录
    void InitAllWds(const char *pcName, bool bRecursion = false);
    int InitNotify();

    static void* DefenceWork(void *args);
    void DefenceWorkFunc();

    static void* ThreadWriteCheck(void *args);
    void WriteCheckFunc();

    inline char *get_proc_path(int pid, char *path, int path_len);





private:

    pthread_t   mDefenceThread;

    map<string, long> mWriteMap;

    int mStatus;

    char mTmpPath[256];

    pthread_mutex_t mMutex;



    struct pollfd mFds[1];
    int miNotifyFd;
    int miWds[MAX_FILES_MONITOR];
    int miCount;
    std::map<int, std::string> mFileDirMap;
    int miFdsNum;

protected:
    DefenObserver   *mObserver;
};


#endif // DEFENMODPROXY_H
