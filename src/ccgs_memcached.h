
#ifndef __CCGS_MEMCACHED_H
#define __CCGS_MEMCACHED_H

#include <libmemcached/memcached.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class CMemcached
{
    public:
        ~CMemcached ();
        CMemcached ();

        int insert (const char* key, const char* value, time_t expiration = 5, uint32_t flags = 0);
        string select (const char* key);

        static CMemcached* getInstance ();

    private:
        memcached_st* memc;
        static CMemcached* pInstance;
};

#define MEMCACHED CMemcached::getInstance()

#endif  // __CCGS_MEMCACHED_H
