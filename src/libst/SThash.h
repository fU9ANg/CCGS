#ifndef _ST_HASH_H
#define _ST_HASH_H

#include "STbase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ST_hash_node {
    void *data;
    ST_linker_t link;
}ST_hash_node_t;

typedef unsigned int (*ST_hash_index)(void *key);
typedef BOOL (*ST_hash_compare)(void *data, void *key);
typedef void (*ST_hash_destroy) (void *data);

typedef struct _ST_hash {
    int size;
    int num_objs;
    struct _ST_hash_node *table;

    ST_hash_index   hash_index;
    ST_hash_compare hash_compare;
    ST_hash_destroy hash_destroy;
}ST_hash_t;


extern int ST_hash_init (ST_hash_t *hash, 
                         int size,
                         ST_hash_index index_routine,
                         ST_hash_compare compare_routine,
                         ST_hash_destroy destroy_routine);

extern int ST_hash_add_object (ST_hash_t *hash, void *data, void *key);
extern void ST_hash_remove_object (ST_hash_t *hash, void *key);
extern void *ST_hash_get_object (ST_hash_t *hash, void *key);
extern ST_hash_node_t *ST_hash_get_node (ST_hash_t *hash, void *key);

extern void **ST_hash_list (ST_hash_t *hash, int *num);
extern void ST_hash_remove_all_objects (ST_hash_t *hash);
extern void ST_hash_release (ST_hash_t *hash);

#ifdef __cplusplus
}
#endif

#endif
