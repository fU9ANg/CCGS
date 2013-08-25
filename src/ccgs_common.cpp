#include <unistd.h>
#include <string.h>
#include <sys/socket.h>

#include "ccgs_common_buffer.h"
#include "ccgs_singleton.h"
#include "ccgs_utils.h"
#include "devel/CCGS_common.h"


struct msg_header {
    unsigned int length;
    unsigned int reserved;
};

#ifdef __cplusplus
extern "C" {
#endif

unsigned int ccgs_send_data (int skfd,
                             unsigned int MID,
                             const void *data, 
                             unsigned int size)
{
#if 0    
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
#endif

    struct msg_header *msg;
    ccgs_header_t     *ccgs_hdr;
    void  *msgbuf = NULL;
    unsigned int retsend = 0;
 
    retsend = sizeof (struct msg_header) + SZCCGSHDR + size;
    msgbuf = malloc (retsend);

    if (msgbuf) {
        msg = (struct msg_header*)msgbuf;
        ccgs_hdr = (ccgs_header_t*)((char*)msgbuf + sizeof (struct msg_header));
        
        memcpy ((char*)msgbuf+sizeof (struct msg_header)+SZCCGSHDR, data, size);
 
        msg->length = retsend;
        msg->reserved = 0;

        memcpy (ccgs_hdr->identifier, CCGS_IDENTIFIER, 4);
        ccgs_hdr->MID = MID;
        ccgs_hdr->status = 0;
        ccgs_hdr->flags  = 0;
        ccgs_hdr->TID    = 0;
        ccgs_hdr->length = size;

        retsend = send_v (skfd, msgbuf, retsend);

        free (msgbuf);
        return retsend;
    }
    return -1;
}

unsigned int ccgs_recv_data (int skfd,
                             void **data,
                             unsigned int MID)
{
    struct msg_header msg;
    unsigned int szrecv = 0,
                 szlen  = 0;
    ccgs_header_t   *ccgs = NULL;
    char *dataptr = NULL;

    *data = NULL;
    do {
        if (*data) {
            free (*data);
        }
       
        if (recv_v (skfd, &msg, sizeof (msg)) <= 0) {
            return 0;
        }

        szrecv = msg.length - sizeof (struct msg_header);
        *data = malloc (szrecv);
        if (data == NULL) {
            return 0;
        }

        dataptr = (char*)*data;
        while (szrecv > 0) {
            szlen = recv_v (skfd, dataptr, 1000);
            if (szlen <= 0) {
                return 0;
            }

            szrecv  -= szlen;
            dataptr += szlen;
        }

        ccgs = (ccgs_header_t*)*data;

        if (!memcmp (ccgs->identifier, CCGS_IDENTIFIER, 4) &&
            ccgs->MID == MID) {
            break;
        }
    } while (1);

    szrecv  = msg.length - sizeof (struct msg_header) - SZCCGSHDR;
    dataptr = (char*)*data + sizeof (struct msg_header) + SZCCGSHDR;
    memmove (*data, dataptr, szrecv);
             
    return szrecv;
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

#ifdef __cplusplus
}
#endif
