#ifndef __CCGS_PROTOCOL_H
#define __CCGS_PROTOCOL_H

#define ECCGS_MODULE_NOT_FOUND 1

#define CCGS_IDENTIFIER "CCGS"

typedef struct ccgs_header {
    /*
     * CCGS protocol identifier, the server will test if
     * a packet is correct CCGS data with this identifier.
     */
    unsigned char identifier[4];

    /*
     * the transaction ID, which tells you the response from 
     * remote is relatived to which request from local.
     */
    unsigned int  TID;
    unsigned short flags;

    /*
     *  the request status.
     */
    unsigned short status;

    /*
     * the module ID, which tells server that the request will
     * be processed by the module relatived to the ID.
     */
    unsigned int   MID;

    /*
     * the length of following data.
     */
    unsigned int   length;
}ccgs_header_t;

#define SZCCGSHDR   ((sizeof (ccgs_header_t)))

#endif //__CCGS_PROTOCOL_H
