
#ifndef _CCGS_THREAD_POOL_H_
#define _CCGS_THREAD_POOL_H_

#include <pthread.h>
#include <stdio.h>
#include <list>
#include <signal.h>

#include "ccgs_common_queue.h"
#include "ccgs_thread_task.h"
#include "ccgs_atomic.h"
#include "ccgs_thread_mutex.h"

class CThreadPool
{
    public:
        CThreadPool (int n);
        ~CThreadPool ();
        int Start ();
        int Stop  ();
        int Kill  ();
        int PushTask (threadTask* p);
        static void* Thread (void* p);
        static void SigHandler (int signo);
        int GetCount ();
        int GetFree  ();

    private:
        list<pthread_t>     threadList;
        CQueue<threadTask*> taskQueue;
        CAtomic <int>       state;
        CAtomic <int>       free;
        int                 count;
        CMutex              threadLock;
};

#endif  //_CCGS_THREAD_POOL_H_
