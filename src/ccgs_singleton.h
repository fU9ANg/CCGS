
#ifndef _CCGS_SINGLETON_H_
#define _CCGS_SINGLETON_H_

#include <stdio.h>
#include "ccgs_atomic.h"
#include "ccgs_common_queue.h"
#include "ccgs_mem_pool.h"
#include "ccgs_common_buffer.h"

class Singleton 
{
    public:
        ~Singleton ();
        static class Singleton* GetInstance ();

        CQueue<CommBuf*> recvQueue;
        CQueue<CommBuf*> sendQueue;
        CMemPool<CommBuf>  memPool;
    private:
        Singleton();
        static class Singleton* instance;
};

#define SINGLETON Singleton::GetInstance()

#endif
