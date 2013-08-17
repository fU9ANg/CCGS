
#ifndef _CCGS_COMMON_QUEUE_H_
#define _CCGS_COMMON_QUEUE_H_

#include <queue>
#include <iostream>
#include <time.h>
#include <pthread.h>

#include "ccgs_thread_mutex.h"

using namespace std;

template <typename TYPE>
class CQueue
{
public:
    CQueue ()
    {
        pthread_mutex_init (&mutex, NULL);
        pthread_cond_init  (&cond,  NULL);
    }

    ~CQueue ()
    {
        pthread_mutex_destroy (&mutex);
        pthread_cond_destroy  (&cond);
    }

    int OutQueue (TYPE& out, unsigned int timeout)
    {
        struct timespec t;
        t.tv_sec = time (NULL) + timeout;
        t.tv_nsec = 0;
        pthread_mutex_lock (&mutex);
        while  (typeQueue.empty ()) {
            if  (0 != pthread_cond_timedwait (&cond, &mutex, &t)) {
                //timeout
                pthread_mutex_unlock (&mutex);
                return (-1);
            } 
        }
        out = typeQueue.front ();
        typeQueue.pop ();
        pthread_mutex_unlock (&mutex);
        return (0);
    }

    int InQueue (TYPE t)
    {
        pthread_mutex_lock (&mutex);
        if (typeQueue.empty ()) {
            typeQueue.push (t);
            pthread_mutex_unlock (&mutex);
            pthread_cond_signal (&cond);
        } else {
            typeQueue.push (t);
            pthread_mutex_unlock (&mutex);
        }
        return (0);
    }

    size_t Size ()
    {
        pthread_mutex_lock (&mutex);
        size_t size = typeQueue.size ();
        pthread_mutex_unlock (&mutex);
        return (size);
    }

private:
    pthread_mutex_t mutex;
    pthread_cond_t  cond;
    queue<TYPE>     typeQueue;
};

#endif
