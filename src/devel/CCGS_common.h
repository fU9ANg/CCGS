#ifndef _CCGS_COMMON_H
#define _CCGS_COMMON_H


#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif


#include "CCGS_module.h"
#include "CCGS_proto.h"

/*
 *  allocate the memory,which is used to send/receive data.
 */
extern ccgs_sockbuf_t *ccgs_sockbuf_alloc ();

/*
 * use it to free a memory allocated with ccgs_mod_alloc before.
 */
extern void ccgs_sockbuf_free (ccgs_sockbuf_t *);

/*
 * add data into send queue, 
 */
extern int ccgs_add_into_queue (ccgs_sockbuf_t *);

/*
 * use the following function to get socket descriptor with the
 * ccgs_sockbuf_t argument passed by mod_handler in the ccgs_module_t
 * structure.
 */
extern int ccgs_get_socket_descriptor (const ccgs_sockbuf_t*);

/*
 * you can use this to set a socket descriptor which the packet
 * will be sent to.the default value is where the packet came from.
 */
extern void ccgs_set_remote_descriptor (ccgs_sockbuf_t*, int);



/*
 * the following function will add a CCGS header at the front of
 * data.
 */
extern unsigned int ccgs_send_data (int skfd, 
                                    const void *data, 
                                    unsigned int size);

extern void *ccgs_make_buffer (unsigned int MID,
                               const void *buf,
                               unsigned int *szbuf);

#ifdef __cplusplus
}
#endif

#endif //_CCGS_COMMON_H
