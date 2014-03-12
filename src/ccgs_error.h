#ifndef CCGS_ERROR_H
#define CCGS_ERROR_H

#define ECCGS_EXCEED_TRANSIZE  1
#define ECCGS_INVALID_MODULE  2

#ifdef __cplusplus
extern "C" {
#endif

void *ccgs_error_reply (int errcode);

#ifdef __cplusplus
}
#endif

#endif
