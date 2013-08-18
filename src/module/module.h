#ifndef __CCGS_MOD_H
#define __CCGS_MOD_H

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

struct ccgs_module;
/*
 * the module initialization function, which will be
 * called while module loaded.
 */
typedef int (*ccgs_module_load)(struct ccgs_module*);

/*
 * the core handler for requests from client,it's important 
 * to understant its the mechanism, it will be called while
 * a request arrived.
 */
typedef int (*ccgs_module_handler)(struct ccgs_module*, ccgs_commbuf_t *buf);

/*
 * the ccgs_module_exit performs some operations to release
 * resources allocated before.
 */

typedef void (*ccgs_module_unload)(struct ccgs_module*);


/*
 * every module must impelment the following structure.
 */
typedef struct ccgs_module {
    unsigned int mod_version;
    void        *mod_private;

    ccgs_module_load    mod_load;
    ccgs_module_handler mod_handler;
    ccgs_module_unload  mod_unload;
}ccgs_module_t;

#define CCGS_MODULE_SYMBOL "ccgs_module"

#define DEFINE_CCGS_MODULE(_version, _mod_load, _mod_handler, _mod_unload) \
            ccgs_module_t MODULE_ENTRY ccgs_module = { \
                .mod_version = _version, \
                .mod_private = NULL, \
                .mod_load    = _mod_load, \
                .mod_handler = _mod_handler, \
                .mod_unload  = _mod_unload, \
            };

//allocate a memory for network communication.
extern void* ccgs_mod_alloc_comm_buf (unsigned int *size);
extern ccgs_module_t *ccgs_mod_get_module (unsigned int id);

#ifdef __cplusplus
}
#endif

#endif
