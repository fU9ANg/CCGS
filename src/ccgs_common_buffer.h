
#ifndef _CCGS_COMMON_BUFFER_H_
#define _CCGS_COMMON_BUFFER_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define     MAX_BUF     4096

class CommBuf 
{
public:
    CommBuf (size_t nSize = MAX_BUF)
    {
        buffSize  = nSize;
        dataPtr   = malloc (buffSize);
        socketFd  = 0;
        buffId    = 0;
    }

    ~CommBuf ()
    {
        if  (dataPtr != NULL)
        {
            free (dataPtr);
            dataPtr = NULL;
        }
    }

    CommBuf (CommBuf& b)
    {
        buffSize = b.buffSize;
        this->dataPtr = malloc (buffSize);
        (void) memcpy (this->dataPtr, b.dataPtr, buffSize);
    }

    void* Data ()
    {
        return (dataPtr);
    }

    size_t SetSize (size_t n)
    {
        return (usedSize = n);
    }

    size_t Size ()
    {
        return (buffSize);
    }

    size_t UsedSize ()
    {
        return (usedSize);
    }

    void Reset ()
    {
        (void) memset (dataPtr, 0x00, buffSize);
    }

    int SocketFd ()
    {
        return socketFd;
    }

    void SetSocket (int fd)
    {
        socketFd = fd;
    }

    int GetId ()
    {
        return (buffId);
    }

    void SetId (int id)
    {
        buffId = id;
    }

    CommBuf& operator= (CommBuf& b)
    {
        (void) memcpy (this->dataPtr, b.Data (), buffSize);
        return (*this);
    }

public:
    void*   dataPtr;
    size_t  buffSize;
    size_t  usedSize;
    int     socketFd;
    int     buffId;
};

#endif  // _CCGS_COMMON_BUFFER_H
