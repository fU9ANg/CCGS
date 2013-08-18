#ifndef __CCGS_MOD_H
#define __CCGS_MOD_H

#if defined (WINNT) || defined (WINDOWS)
#define MODULE_ENTRY __declspec(dllexport)
#else
#define MODULE_ENTRY
#endif

#define MOD_VERSION(maj,min) \
         ((maj & 0x0000FFFF) << 16 | (min & 0x0000FFFF))

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*module_init) ();

typedef struct _ccgs_module {
    unsigned int mod_ver;
    unsigned int mod_id;
}ccgs_module_t;



#ifdef __cplusplus
}
#endif

#endif
