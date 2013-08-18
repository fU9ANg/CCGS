#ifndef __CCGS_MOD_H
#define __CCGS_MOD_H

#include <stdio.h>
#include <stdlib.h>

#if defined (WINNT) || defined (WINDOWS)
#define MODULE_ENTRY __declspec(dllexport)
#else
#define MODULE_ENTRY
#endif

#define MOD_VERSION(maj,min) \
         ((maj & 0x0000FFFF) << 16 | (min & 0x0000FFFF))
#define MOD_MINOR(ver) (ver & 0x0000FFFF)
#define MOD_MAJOR(ver) ((ver & 0xFFFF0000) >> 16)


#ifdef __cplusplus
extern "C" {
#endif

typedef struct ccgs_commbuf {
    int sockfd;
    unsigned int szbuf;
    void *buf;
}ccgs_commbuf_t;

/*
 * the core structure for each module to implement.
 */

typedef struct ccgs_module {
    unsigned int mod_version;
    void         *mod_private;
    /*
     * the module initialization function, which will be
     * called while module loaded.
     */
    int (*mod_load)(struct ccgs_module*);

    /*
     * the core handler for requests from client,it's important 
     * to understant its the mechanism, it will be called while
     * a request arrived.
     */
    int (*mod_handler)(struct ccgs_module*, ccgs_commbuf_t *buf);

    /*
     * the ccgs_module_exit performs some operations to release
     * resources allocated before.
     */

    void (*mod_unload)(struct ccgs_module*);
}ccgs_module_t;

/*
 * the export symbol of each module.
 */
#define CCGS_MODULE_SYMBOL "ccgs_module"



/*
 * use the following macro to define a module entry.
 */
#define DEFINE_CCGS_MODULE(_version, _mod_load, _mod_handler, _mod_unload) \
            ccgs_module_t MODULE_ENTRY ccgs_module = { \
                .mod_version = _version, \
                .mod_private = NULL, \
                .mod_load    = _mod_load, \
                .mod_handler = _mod_handler, \
                .mod_unload  = _mod_unload, \
            }


/*
 * get a module with the module ID configured in the file.
 */
extern ccgs_module_t *ccgs_mod_get_module (unsigned int id);


#ifdef __cplusplus
}
#endif

#endif
