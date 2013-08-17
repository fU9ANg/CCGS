
#ifndef _CCGS_UTILS_H_
#define _CCGS_UTILS_H_

#include <stdio.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @param   fd      socket fd
 * @param   buf     buffer to send
 * @param   left    bytes to send
 * @param   timeout timeout
 */
extern ssize_t send_n (int fd, void* pdata, ssize_t left, struct timeval* timeout);

extern int send_v (int fd, void* pdata, ssize_t left);

/**
 * @param fd      socket fd
 * @param buf     buffer to store recv data
 * @param left    bytes to recv
 * @param timeout timeout
 */
extern ssize_t recv_n (int fd, void* pdata, ssize_t left, struct timeval* timeout);

extern int recv_v (int fd, void* pdata, ssize_t left);

extern void Send2 (int fd, void* pdata, ssize_t left);

#ifdef __cplusplus
}
#endif

#endif //_CCGS_UTILS_H_
