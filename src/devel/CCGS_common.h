#ifndef _CCGS_COMMON_H
#define _CCGS_COMMON_H


#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif


#include "CCGS_proto.h"

/*
 * the following function will add a CCGS header at the front of
 * data.
 */
extern unsigned int ccgs_send_data (int skfd, unsigned int MID, 
                                    const void *data, unsigned int size);

#ifdef __cplusplus
}
#endif

#endif //_CCGS_COMMON_H
