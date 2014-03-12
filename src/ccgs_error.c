#include "ccgs_error.h"
#include "devel/CCGS_proto.h"

ccgs_header_t  __ccgs_error_list[] = {
    [ECCGS_EXCEED_TRANSIZE] = {
        .identifier = 12,
        .flags      = 0,
        .status     = (ECCGS_EXCEED_TRANSIZE << 8) & 0xFF00,
        .MID        = 0,
        .TID        = 0,
        .length     = 0,
    },

    [ECCGS_INVALID_MODULE] = {
        .identifier = 13,
        .flags      = 0,
        .status     = (ECCGS_INVALID_MODULE << 8) & 0xFF00,
        .MID        = 0,
        .TID        = 0,
        .length     = 0,
    }
};

void *ccgs_error_reply (int errcode)
{
    return (void*)&__ccgs_error_list[errcode];
}
