#include <unistd.h>
#include <string.h>
#include <sys/socket.h>

#include "ccgs_common_buffer.h"
#include "ccgs_singleton.h"
#include "devel/CCGS_common.h"

struct msg_header {
    unsigned int length;
    unsigned int reserved;
};

unsigned int ccgs_send_data (int skfd,
                             const void *data, 
                             unsigned int size)
{
    
    struct iovec  iovec[2];
    struct msg_header msg;
    struct msghdr ccgs_data;

    msg.length = sizeof (struct msg_header) + size;
    msg.reserved = 0;

    iovec[0].iov_base = (void*)&msg;
    iovec[0].iov_len  = sizeof (struct msg_header);

    iovec[1].iov_base = (void*)data;
    iovec[1].iov_len  = size;

    ccgs_data.msg_name = NULL;
    ccgs_data.msg_namelen = 0;
    ccgs_data.msg_iov      = &iovec[0];
    ccgs_data.msg_iovlen   = 2;
    ccgs_data.msg_control  = NULL;
    ccgs_data.msg_controllen = 0;
    return sendmsg (skfd, &ccgs_data, 0);
}

void *ccgs_make_buffer (unsigned int MID,
                        const void *data,
                        unsigned int size,
                        unsigned int *retsz)
{
    ccgs_header_t *ccgs_hdr = NULL;
    void      *buffer = NULL;

    buffer = calloc (1, size + SZCCGSHDR);
    if (buffer) {
        ccgs_hdr = (ccgs_header_t*)buffer;

        memcpy (ccgs_hdr->identifier, CCGS_IDENTIFIER, 4);
        ccgs_hdr->MID = MID;
        ccgs_hdr->status = 0;
        ccgs_hdr->flags  = 0;
        ccgs_hdr->TID    = 0;
        ccgs_hdr->length = size;
        
        memcpy ((char*)buffer + SZCCGSHDR, data, size);

        *retsz = size + SZCCGSHDR;
    }

    return buffer;
}

ccgs_sockbuf_t *ccgs_sockbuf_alloc (unsigned int size)
{
    ccgs_sockbuf_t  *skbuf = NULL;
    CommBuf         *combuf= NULL;
    void            *bufptr= NULL;

    skbuf = (ccgs_sockbuf_t*)calloc (1, sizeof (ccgs_sockbuf_t));
    if (skbuf == NULL) {
        return NULL;
    }

    combuf = new CommBuf (size + SZCCGSHDR);
    combuf->socketFd = -1;

    bufptr = combuf->dataPtr;

    skbuf->intrptr= combuf;

    skbuf->header = (ccgs_header_t*)bufptr;
    skbuf->buffer = (char*)bufptr + SZCCGSHDR;
    skbuf->size   = size;
    skbuf->data_length = 0;

    memcpy (skbuf->header->identifier, CCGS_IDENTIFIER, 4);
    return skbuf;
}

void ccgs_sockbuf_free (ccgs_sockbuf_t *skbuf)
{
    CommBuf *combuf = (CommBuf*)skbuf->intrptr;

    if (combuf) {
        delete combuf;
    }

    free (skbuf);
}

int ccgs_add_into_queue (ccgs_sockbuf_t *skbuf, unsigned int mid)
{
#if 0
    if (skbuf->intrptr) {
        /*
         * the buffer will be released automatically,so
         * we don't release anymore here,just assign empty
         * pointer to it.
         */
        SINGLETON->sendQueue.InQueue ((CommBuf*)skbuf->intrptr);
        skbuf->intrptr = NULL;
    }
#endif
    if (skbuf) {
        SINGLETON->moduleManager.addMBufferIntoQueue ((void*)skbuf, mid);
    }
    return 0;
}

int ccgs_get_socket_descriptor (const ccgs_sockbuf_t *skbuf)
{
    CommBuf *combuf = (CommBuf*)skbuf->intrptr;

    if (combuf) {
        return combuf->socketFd;
    }

    return -1;
}

void ccgs_set_socket_descriptor (const ccgs_sockbuf_t *skbuf, int sock)
{
    CommBuf *combuf = (CommBuf*)skbuf->intrptr;

    if (combuf) {
        combuf->socketFd = sock;
    }
}
