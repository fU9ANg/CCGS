#ifndef _CCGS_PROTOCOL_HANDLER_H
#define _CCGS_PROTOCOL_HANDLER_H

#include "ccgs_common_buffer.h"
#include "ccgs_singleton.h"
#include "devel/CCGS_module.h"
#include "devel/CCGS_proto.h"

class CProtocolHandler {
public:
    static void handle (CommBuf *buf) {
        ccgs_sockbuf_t *skbuf   = NULL;
        ccgs_sockbuf_t *sndbuf  = NULL;
        static CModule *module  = NULL;
        CQueue<void*>  *skbufQueue = NULL;
        CommBuf        *comBuf  = NULL;

        skbuf = (ccgs_sockbuf_t*)calloc (1, sizeof (ccgs_sockbuf_t));
        if (skbuf == NULL) {
            return;
        }

        skbuf->intrptr = (void*)buf;
        skbuf->header  = (ccgs_header_t*)buf->dataPtr;
        skbuf->buffer  = (char*)buf->dataPtr + SZCCGSHDR;
        skbuf->size    = buf->buffSize;
        skbuf->data_length = buf->usedSize-SZCCGSHDR;

        printf ("[CCGS]recived data [length: %u]\n", skbuf->data_length);

        if (module == NULL ||
            module->m_id != skbuf->header->MID) {
            module = SINGLETON->moduleManager.getModule (skbuf->header->MID);
        }

        if (module == NULL) { //if the module not found.
            skbuf->header->length = 0;
            skbuf->header->status = ECCGS_MODULE_NOT_FOUND;
            buf->usedSize         = SZCCGSHDR;
            SINGLETON->sendQueue.InQueue (buf);
            free (skbuf);
            return ;
        } else {
            module->m_module->mod_handler (module->m_module, skbuf);

            skbufQueue = SINGLETON->moduleManager.getMBufferQueue (module->m_id);
            
            if (skbufQueue) {
                do {
                    skbufQueue->OutQueue ((void*&)sndbuf, 0);
                    if (sndbuf) {
                        comBuf = (CommBuf*)sndbuf->intrptr;

                        /* set CCGS protocol header */
                        sndbuf->header->TID = skbuf->header->TID;
                        sndbuf->header->MID = skbuf->header->MID;
                        sndbuf->header->status = 0;
                        sndbuf->header->flags  = 0;
                        sndbuf->header->length = sndbuf->data_length;
                       
                        if (comBuf->socketFd <= 0) {
                            comBuf->socketFd         = buf->socketFd;
                        }
                        comBuf->usedSize       = SZCCGSHDR + sndbuf->header->length;

                        SINGLETON->sendQueue.InQueue (comBuf);
                        free (sndbuf);
                    }
                } while (sndbuf);
            }
        }
    }
};


#endif //_CCGS_PROTOCOL_HANDLER_H
