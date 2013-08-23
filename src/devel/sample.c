#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CCGS_module.h"

static int ccgs_module_load (ccgs_module_t *mod, unsigned int mid)
{
    void *data = malloc (10);
    mod->mod_private = data;

    return 0;
}

static int ccgs_module_handler (ccgs_module_t *mod, ccgs_sockbuf_t *skbuf)
{
    printf ("Reiceive data[size: %d]: %s\n",skbuf->data_length, (char*)skbuf->buffer);

    strcpy ((char*)skbuf->buffer,"This is response from server.\n");

    ccgs_add_into_queue (skbuf);
    return 0;
}

static void ccgs_module_unload (ccgs_module_t *mod)
{
    if (mod->mod_private) {
        free (mod->mod_private);
    }
}


DEFINE_CCGS_MODULE (MOD_VERSION (1,1), 
                   ccgs_module_load, 
                   ccgs_module_handler, 
                   ccgs_module_unload);
