#include "module.h"

int ccgs_module_load (ccgs_module_t *mod)
{
    void *data = malloc (10);

    mod->mod_private = data;
    return 0;
}

int ccgs_module_handler (ccgs_module_t *mod, ccgs_commbuf_t *cmmbuf)
{
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
