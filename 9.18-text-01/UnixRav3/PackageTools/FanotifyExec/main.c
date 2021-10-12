#define _GNU_SOURCE
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <poll.h>
#include <errno.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/signalfd.h>
#include <fcntl.h>
#include <time.h>

#include <linux/fanotify.h>
#include <sys/fanotify.h>

/* Structure to keep track of monitored directories */
typedef struct {
  /* Path of the directory */
  char *path;
} monitored_t;

pid_t pid;
/* Size of buffer to use when reading fanotify-cmdline events */
#define FANOTIFY_BUFFER_SIZE 8192

/* Enumerate list of FDs to poll */
enum {
  FD_POLL_SIGNAL = 0,
  FD_POLL_FANOTIFY,
  FD_POLL_MAX
};

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

/* Array of directories being monitored */
static monitored_t *monitors;
static int n_monitors = 1;

static char *get_program_cmdline_from_pid(int pid, char *buffer, size_t buffer_size) {
    int i;
    int fd;
    ssize_t len;
    char *aux;

    /* Try to get program name by PID */
    sprintf(buffer, "/proc/%d/cmdline", pid);
    if ((fd = open(buffer, O_RDONLY)) < 0)
        return NULL;

    /* Read file contents into buffer */
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

static void event_process(int fd, struct fanotify_event_metadata *event) {
        printf("event_process ");

        if(pid == event->pid){
             close(event->fd);
             printf("event_process self end!\n");

            return;
        }



    char path[PATH_MAX];
    time_t current_time;
    char *c_time_string;
    struct fanotify_response response;


    current_time = time(NULL);
    c_time_string = ctime(&current_time);

    printf("%s [%d] Event on '%s' ",
           strtok(c_time_string, "\n"),
           event->pid, get_file_path_from_fd(event->fd, path, PATH_MAX) ? path : "unknown");

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

    printf("\n");
    //printf("Cmdline: %s\n", (get_program_cmdline_from_pid(event->pid, path, PATH_MAX) ? path : "unknown"));

    fflush(stdout);

    close(event->fd);
}

static void shutdown_fanotify(int fanotify_fd) {
    int i;

    for (i = 0; i < n_monitors; ++i) {
        /* Remove the mark, using same event mask as when creating it */
        fanotify_mark(fanotify_fd,
                      FAN_MARK_REMOVE,
                      event_mask,
                      AT_FDCWD,
                      monitors[i].path);
        //free(monitors[i].path);
    }
    free(monitors);
    close(fanotify_fd);
}

char test_path[]="./";

static int initialize_fanotify(int argc, const char **argv) {
    int i;
    int fanotify_fd;
    /* Create new fanotify-cmdline device */
    if ((fanotify_fd = fanotify_init(FAN_CLOEXEC  | FAN_NONBLOCK | FAN_CLASS_NOTIF,
                                     O_RDONLY | O_LARGEFILE)) < 0)
    //if ((fanotify_fd = fanotify_init(FAN_CLOEXEC | FAN_CLASS_CONTENT | FAN_NONBLOCK,
    //                                     O_RDONLY | O_LARGEFILE)) < 0)
    {
        fprintf(stderr,
                "Couldn't setup new fanotify-cmdline device: %s\n",
                strerror(errno));
        return -1;
    }

    /* Allocate array of monitor setups */
    monitors = malloc(n_monitors * sizeof(monitored_t));

    /* Loop all input directories, setting up marks */
    for (i = 0; i < n_monitors; ++i) {
        monitors[i].path = test_path;

        if (fanotify_mark(fanotify_fd,
                          FAN_MARK_ADD,
                          event_mask,
                          AT_FDCWD,
                          monitors[i].path) < 0)
        /*
        if (fanotify_mark(fanotify_fd,
                          FAN_MARK_ADD | FAN_MARK_MOUNT,
                                          FAN_OPEN_PERM | FAN_CLOSE_WRITE, AT_FDCWD,
                          monitors[i].path) < 0)*/
        {
            fprintf(stderr,
                    "Couldn't add monitor in directory '%s': '%s'\n",
                    monitors[i].path,
                    strerror(errno));
            return -1;
        }

        //printf("Started monitoring directory '%s'...\n", monitors[i].path);
    }

    return fanotify_fd;
}

static void shutdown_signals(int signal_fd) {
    close(signal_fd);
}

static int initialize_signals(void) {
    int signal_fd;
    sigset_t sigmask;

    /* We want to handle SIGINT and SIGTERM in the signal_fd, so we block them. */
    sigemptyset(&sigmask);
    sigaddset(&sigmask, SIGINT);
    sigaddset(&sigmask, SIGTERM);

    if (sigprocmask(SIG_BLOCK, &sigmask, NULL) < 0) {
        fprintf(stderr,
                "Couldn't block signals: '%s'\n",
                strerror(errno));
        return -1;
    }

    /* Get new FD to read signals from it */
    if ((signal_fd = signalfd(-1, &sigmask, 0)) < 0) {
        fprintf(stderr,
                "Couldn't setup signal FD: '%s'\n",
                strerror(errno));
        return -1;
    }

    return signal_fd;
}

int main(int argc,
         const char **argv) {

    pid =getpid();
    int signal_fd;
    int fanotify_fd;
    struct pollfd fds[FD_POLL_MAX];

    /* Initialize signals FD */
    if ((signal_fd = initialize_signals()) < 0) {
        fprintf(stderr, "Couldn't initialize signals\n");
        exit(EXIT_FAILURE);
    }

    /* Initialize fanotify-cmdline FD and the marks */
    if ((fanotify_fd = initialize_fanotify(argc, argv)) < 0) {
        fprintf(stderr, "Couldn't initialize fanotify-cmdline\n");
        exit(EXIT_FAILURE);
    }
    /* Clean exit */
    shutdown_fanotify(fanotify_fd);
    shutdown_signals(signal_fd);

    printf("Success\n");

    return EXIT_SUCCESS;
}
