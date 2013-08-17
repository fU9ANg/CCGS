
#ifndef _CCGS_MEM_POOL_H_
#define _CCGS_MEM_POOL_H_

#include <queue>
#include <iostream>
#include <time.h>
#include <pthread.h>

#include "ccgs_thread_mutex.h"

#define MAX_POOL_BUF    20000
using namespace std;

template<typename TYPE>
class CMemPool
{
public:

    CMemPool (int n = MAX_POOL_BUF)
    {
        this->size = n;
        for  (int i = 0; i < this->size; i++)
        {
            TYPE* p = new TYPE;
            this->blockQueue.push (p);
        }
    }

    ~CMemPool ()
    {
        CGuard guard (mutexLock);
        while  (!blockQueue.empty ())
        {
            TYPE* p = this->blockQueue.front ();
            this->blockQueue.pop ();
            delete p;
        }
    }

    TYPE* Malloc ()
    {
        CGuard guard (mutexLock);
        if  (blockQueue.empty ())
        {
            return (NULL);
        }
        TYPE* p = blockQueue.front ();
        blockQueue.pop ();
        return (p);
    }

    int Free (TYPE* i)
    {
        CGuard guard (mutexLock);
        blockQueue.push (i);
        return (0);
    }

    int Size ()
    {
        return (size);
    }

    int Used ()
    {
      CGuard guard (mutexLock);
      return (size - blockQueue.size ());
    }

private:
    queue<TYPE*> blockQueue;
    CMutex mutexLock;
    int size;
};

#endif  //_CCGS_MEM_POOL_H_
