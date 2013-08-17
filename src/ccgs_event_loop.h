
#ifndef CCGS_EVENT_LOOP_H_
#define CCGS_EVENT_LOOP_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/errno.h>
#include <sys/fcntl.h>
#include <list>
#include <time.h>
#include <netinet/tcp.h>
#include <ev.h>

#include "ccgs_thread_mutex.h"
#include "ccgs_thread_task.h"
#include "ccgs_singleton.h"
#include "ccgs_common_buffer.h"
#include "ccgs_utils.h"
#include "ccgs_atomic.h"

#define MAXFD       10240
#define TIMEOUT     10

typedef struct ev_io_info
{
    struct ev_io* io;
    ev_tstamp lasttime;
}   ev_in_info;

class CEvLoop: public threadTask
{
    public:
        CEvLoop (string ip, int port);
        ~CEvLoop ();
        virtual int DoWork ();
        /**
         * @brief callback function for accept,when new client connected;
         */
        static void AcceptCB (struct ev_loop *loop, ev_io *w, int revents);
        /**
         * @brief callback function when received some data from client;
         */
        static void RecvCB (struct ev_loop *loop, ev_io *w, int revents);

        /**
         * @brief callback function when timeout
         */
        static void TimeOutCB (struct ev_loop *loop, struct ev_timer *timer, int revents);
        /**
         * @brief set the fd as nonblock
         */
        static void SetNonblock  (int fd);
        static void SetReuseAddr (int fd);
        static void SetNodelay   (int fd);
        /**
         * @brief disconnect the client
         * @param[in] fd    the client to disconnect
         */
        static void CloseFD (int fd);

        /** event loop struct*/
        static struct ev_loop* loop;

        //用来记录每个fd的信息，ev_io*和上次收到数据的时间
        static struct ev_io_info ioarray[MAXFD];

        int GetClientCount ();

    private:
        static CAtomic<int> clientcount;
        int    recvbuf (int fd);
        int    StartListen ();
        int    m_listenfd;
        int    m_port;
        string m_ip;
};

#endif
