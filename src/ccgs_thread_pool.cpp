
#include "ccgs_thread_pool.h"

CThreadPool::CThreadPool (int n) : free(0)
{
    count = n;
}

CThreadPool::~CThreadPool ()
{
    // TODO:
}

int CThreadPool::Start ()
{
    state = 1;
    for (int i = 0; i < count; ++i)
    {
        pthread_t tid = 0;
        pthread_create (&tid, 0, CThreadPool::Thread, this);
        CGuard gard (threadLock);
        this->threadList.push_back (tid);
    }

    return (0);
}

int CThreadPool::Stop ()
{
    state = 0;
    while (0 != this->GetCount ())
    {
        usleep (100);
    }

    return (0);
}

int CThreadPool::PushTask (threadTask* p)
{
    return (this->taskQueue.InQueue (p));
}

int CThreadPool::GetCount ()
{
    CGuard gard (threadLock);
    return (this->threadList.size ());
}

void* CThreadPool::Thread (void* p)
{
    signal (SIGRTMIN, SigHandler);
    CThreadPool* pp = static_cast<CThreadPool*> (p);
    threadTask * t  = NULL;

    while (pp->state.Value () != 0)
    {
        if (pp->taskQueue.OutQueue (t, 3) == 0 && t != NULL)
        {
            pp->free ++;
            t->DoWork ();
            pp->free --;
            if (t->exitOfFinish)
            {
                delete t;
                t = NULL;
            }
        }
        else
        {
            t = NULL;
        }
    }

    CGuard gard (pp->threadLock);
    pp->threadList.remove (pthread_self ());

    return (NULL);
}

int CThreadPool::Kill ()
{
    CGuard gard (this->threadLock);
    while (!threadList.empty ())
    {
        cout << ".l........." << endl;
        pthread_kill (threadList.front (), SIGRTMIN);
        threadList.pop_front ();
    }

    return (0);
}

void CThreadPool::SigHandler (int signo)
{
    printf ("[%ld]exit\n", (long unsigned int)pthread_self ());
    pthread_exit (NULL);
    return;
}
