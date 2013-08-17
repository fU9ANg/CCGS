
#ifndef _CCGS_THREAD_MUTEX_H_
#define _CCGS_THREAD_MUTEX_H_

#include <pthread.h>

class CMutex
{
    public:
        CMutex ()
        {
            pthread_mutex_init (&mutex, NULL);
        }

        ~CMutex ()
        {
            pthread_mutex_destroy (&mutex);
        }

        void Lock ()
        { 
            pthread_mutex_lock (&mutex);
        }

        void UnLock ()
        { 
            pthread_mutex_unlock (&mutex);
        }

        pthread_mutex_t* GetMutex ()
        { 
            return (&mutex);
        }

    private:
        CMutex (const CMutex& m);
        const CMutex& operator= (const CMutex&);
        pthread_mutex_t mutex;
};

class CGuard
{
    public:
        explicit CGuard (CMutex& m) : mutex (m)
        { 
            mutex.Lock ();
        }

        ~CGuard ()
        { 
            mutex.UnLock ();
        }
    private:
        CGuard (const CGuard& t);
        const CGuard& operator= (const CGuard&);
        CMutex& mutex;
};

class CCondition
{
    public:
        CCondition (CMutex& m) : mutex (m)
        {
            pthread_cond_init (&cond, NULL);
        }

        int Wait ()
        {
            pthread_cond_wait (&cond, mutex.GetMutex ());
            return (0);
        }

        int Wait (time_t t)
        {
            struct timespec timeout;
            timeout.tv_sec  = time (NULL) + t;
            timeout.tv_nsec = 0;
            return (pthread_cond_timedwait (&cond, mutex.GetMutex (), &timeout));
        }

        void Notify ()
        {
            pthread_cond_signal (&cond);
        }

        void NotifyAll ()
        {
            pthread_cond_broadcast (&cond);
        }

        ~CCondition ()
        {
            pthread_cond_destroy (&cond);
        }

    private:
        CCondition (const CCondition& t);
        CMutex&        mutex;
        pthread_cond_t cond;
};

#define CGuard(x) static_assert (false, "missing mutex guard variable name")

#endif  // _CCGS_THREAD_MUTEX_H_
