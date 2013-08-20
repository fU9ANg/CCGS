
#ifndef _CCGS_LOGIC_H_
#define _CCGS_LOGIC_H_

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>
#include <sys/file.h>

#include "glog/logging.h"

#include "ccgs_thread_pool.h"
#include "ccgs_thread_task.h"
#include "ccgs_recv_task.h"
#include "ccgs_send_task.h"
#include "ccgs_event_loop.h"
#include "ccgs_common_buffer.h"

#define CONFIGFILE "./config.lua"

enum
{
    LOCK_WAIT   = LOCK_EX,
    LOCK_NOWAIT = LOCK_EX | LOCK_NB,
    UNLOCK      = LOCK_UN
};

class CManager
{
    public:
        CManager ();
        ~CManager ();
        int Process (int argc, char** argv);
        int Run ();
        static void SigHandler (int signo);

    private:
        bool InitSystemManager ();
        void ReleaseSystem ();
    private:
        bool Lock (int mode);
        CThreadPool* threadPool;
        int          fileLock;
};

#endif  //_CCGS_LOGIC_H_
