#include <string.h>
#include "ccgs_memcached.h"
#include "ccgs_configure.h"

using namespace std;
CMemcached* CMemcached::pInstance = NULL;

CMemcached* CMemcached::getInstance ()
{
    if (pInstance == NULL)
    {
        pInstance = new CMemcached ();
    }
    return (pInstance);
}

CMemcached::CMemcached ()
{
    memcached_return rc;
    memcached_server_st* server = NULL;

    memc    = memcached_create (NULL);
    server  = memcached_server_list_append (server, CONFIG->mc_server.c_str(), CONFIG->mc_port, &rc);
    rc      = memcached_server_push (memc, server);

    if (rc != MEMCACHED_SUCCESS)
        cout << "memcached_server_push failed! rc: " << rc << endl;
};

CMemcached::~CMemcached ()
{
    memcached_free (memc);
}

int CMemcached::insert (const char* key, const char* value, time_t expiration, uint32_t flags)
{
    if (key == NULL || value == NULL)
        return (-1);

    //uint32_t flags = 0;

    memcached_return rc;
    rc = memcached_set (memc, key, strlen (key), value, strlen (value), expiration, flags);

    // insert success
    if (rc == MEMCACHED_SUCCESS)
        return (1);
    else
        return (0);
}

string CMemcached::select (const char* key)
{
    if (NULL == key)
        return "";

    uint32_t flags = 0;
    memcached_return rc;

    size_t value_length;
    char* value = memcached_get (memc, key, strlen (key), &value_length, &flags, &rc);

    // select success
    if (rc == MEMCACHED_SUCCESS)
        return (value);

    return ("");
}
