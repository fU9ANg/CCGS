#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CCGS_common.h"

static int ccgs_module_load (ccgs_module_t *mod, unsigned int mid)
{
    return 0;
}

static int ccgs_module_handler (ccgs_module_t *mod, ccgs_sockbuf_t *skbuf)
{
    printf ("Reiceive data[size: %d]: %s\n",skbuf->data_length, (char*)skbuf->buffer);

    strcpy ((char*)skbuf->buffer,"How are you");
    skbuf->data_length = strlen ("How are you");

    ccgs_add_into_queue (skbuf);
    return 0;
}

static void ccgs_module_unload (ccgs_module_t *mod)
{
}


DEFINE_CCGS_MODULE (MOD_VERSION (1,1), 
                   ccgs_module_load, 
                   ccgs_module_handler, 
                   ccgs_module_unload);
