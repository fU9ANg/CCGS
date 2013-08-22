#include "module.h"

int ccgs_module_load (ccgs_module_t *mod)
{
    void *data = malloc (10);
    mod->mod_private = data;

    return 0;
}

int ccgs_module_handler (ccgs_module_t *mod, ccgs_commbuf_t *cmmbuf)
{
    void *data = cmmbuf->bufptr;
    unsigned int szbuf = cmmbuf->szbuf;
    ccgs_commbuf_t *newbuf = NULL;

    /*use this way to allocate a new network buffer.*/
    newbuf = ccgs_mod_alloc ();


    //TODO: add code here to handle the request from client.

    ccgs_mod_add_send_queue (newbuf);

    ccgs_mod_free (cmmbuf);

    return 0;
}

void ccgs_module_unload (ccgs_module_t *mod)
{
    if (mod->mod_private) {
        free (mod->mod_private);
    }
}


DEFINE_CCGS_MODULE (MOD_VERSION (1,1), 
                   ccgs_module_load, 
                   ccgs_module_handler, 
                   ccgs_module_unload);
