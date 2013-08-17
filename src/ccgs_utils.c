
#include "ccgs_utils.h"

ssize_t send_n (int fd, void* pdata, ssize_t left, struct timeval* timeout)
{
    if (pdata == NULL || timeout == NULL)
        return (-1);

    ssize_t recved = 0;
    fd_set st;

    while(left != 0)
    {
        FD_ZERO (&st);
        FD_SET (fd, &st);
        int i = select (fd + 1, NULL, &st, NULL, timeout);
        if (i <= 0)
        {
            break;
        }
        else
        {
            ssize_t len = send (fd, pdata + recved, left, 0);
            if (len == 0)
            {
                break;
            }
            if (len == -1)
            {
                return (-1);
            }

            left   -= len;
            recved += len;
        }
    }
    return (0);
}

ssize_t recv_n (int fd, void* pdata, ssize_t left, struct timeval* timeout)
{
    if (pdata == NULL || timeout == NULL)
        return (-1);

    ssize_t recved = 0;
    fd_set st;
    while (left != 0)
    {
        FD_ZERO (&st);
        FD_SET (fd, &st);
        int i = select (fd + 1, &st, NULL, NULL, timeout);
        if (i <= 0)
        {
            break;
        }
        else
        {
            ssize_t len = recv (fd, pdata + recved, left, 0);
            if (len == 0)
            {
                break;
            }
            if (len == -1)
            {
                return (-1);
            }

            left   -= len;
            recved += len;
        }
    }

    return (recved);
}

int send_v (int fd, void* pdata, ssize_t left)
{
    if (pdata == NULL)
        return (-1);

    int sended = 0;
    while (left != 0)
    {
        int len = send (fd, pdata + sended, left, 0);

        if (errno == EINTR || errno == EAGAIN)
        {
            usleep (100);
            continue;
        }
        if (len == 0)
        {
            break;
        }
        if (len == -1)
        {
            return (-1);
        }

        left   -= len;
        sended += len;
    }

    return (sended);
}

int recv_v (int fd, void* pdata, ssize_t left)
{
    if (pdata == NULL)
        return (-1);

    int recved = 0;
    while (left != 0)
    {
        int len = recv (fd, (char*) pdata + recved, left, 0);

        if (errno == EINTR || errno == EAGAIN)
        {
            usleep (100);
            continue;
        }
        if (len == 0)
        {
            break;
        }
        if (len == -1)
        {
            return (-1);
        }

        left   -= len;
        recved += len;
    }

    return (recved);
}

void Send2 (int fd, void* pdata, ssize_t left)
{
    int bytes_left = left;
    int written_bytes;
    char* ptr = (char*) pdata;

    while (bytes_left > 0)
    {
        written_bytes = send (fd, ptr, bytes_left, 0);
        if (written_bytes <= 0) {
            if (errno == EINTR) {
                if (written_bytes < 0) {
                    written_bytes = 0;
                    continue;
                }
            }
            else if (errno == EAGAIN) {
                if (written_bytes < 0) {
                    written_bytes = 0;
                    usleep (50);
                    continue;
                }
            }
            else {
                break;
            }
        }

        bytes_left -= written_bytes;
        ptr += written_bytes;
    }
}
