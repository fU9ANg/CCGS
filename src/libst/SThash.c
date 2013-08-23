#include "SThash.h"

int ST_hash_init (ST_hash_t *hash, 
                  int size,
                  ST_hash_index index_routine,
                  ST_hash_compare compare_routine,
                  ST_hash_destroy destroy_routine)
{
    hash->size = size;
    hash->table = calloc (size, sizeof (struct _ST_hash_node));
    if (!hash->table) {
        return -1;
    }

    hash->num_objs   = 0;
    hash->hash_index = index_routine;
    hash->hash_compare = compare_routine;
    hash->hash_destroy = destroy_routine;
    return 0;
}

int ST_hash_add_object (ST_hash_t *hash, void *data, void *key)
{
    unsigned int idx;
    struct _ST_hash_node *node_head = NULL;
    struct _ST_hash_node *node      = NULL,
                        *next      = NULL;

    node = calloc (1, sizeof (struct _ST_hash_node));
    if (node == NULL) {
        return -1;
    }

    node->data = data;

    if (hash->hash_index) {
        idx = hash->hash_index (key);
    }

    node_head = &hash->table[idx % hash->size];
    next = node_head->link.next;
    node->link.prev = node_head;
    node->link.next = next;

    if (node_head) {
        node_head->link.next = node;
    }
    if (next) {
        next->link.prev = node;
    }

    hash->num_objs++;
    return 0;
}

static ST_hash_node_t *ST_hash_get_node (ST_hash_t*, void*);
void ST_hash_remove_object (ST_hash_t *hash, void *key)
{
    ST_hash_node_t *node = NULL,
                   *next = NULL,
                   *prev = NULL;

    node = ST_hash_get_node (hash, key);
    if (node) {
        prev = node->link.prev;
        next = node->link.next;

        if (prev) {
            prev->link.next = next;
        }

        if (next) {
            next->link.prev = prev;
        }

        if (hash->hash_destroy) {
            hash->hash_destroy (node->data);
        }
        hash->num_objs--;
        free (node);
    }
}

static ST_hash_node_t *ST_hash_get_node (ST_hash_t *hash, void *key)
{
    unsigned int idx = 0;
    ST_hash_node_t *node = NULL;

    idx = (hash->hash_index?hash->hash_index (key):idx);
    node = hash->table[idx % hash->size].link.next;

    while (node && hash->hash_compare) {
        if (hash->hash_compare (node->data, key)) {
            return node;
        }
        node = node->link.next;
    }

    return NULL;
}

void *ST_hash_get_object (ST_hash_t *hash, void *key)
{
    ST_hash_node_t *node = NULL;

    node = ST_hash_get_node (hash, key);
    return node?node->data:NULL;
}

void *ST_hash_next_object (ST_hash_t *hash, void *key,void **ptr)
{
    ST_hash_node_t *nodeptr = NULL;
    unsigned int idx = 0;

    if (hash) {
        idx = (hash->hash_index?hash->hash_index (key):idx);
        nodeptr = hash->table[idx % hash->size].link.next;
    } else {
        nodeptr = *ptr;
    }

    if (nodeptr) {
        *ptr = nodeptr->link.next;
    }

    return nodeptr?nodeptr->data:NULL;
}

void **ST_hash_list (ST_hash_t *hash, int *num)
{
    int i = 0, j = 0;
    struct _ST_hash_node *node_pos = NULL;
    void **objs = NULL;

    *num = hash->num_objs;
    objs = calloc (*num, sizeof (void*));
    if (objs == NULL) {
        return NULL;
    }

    for (i=0; i<hash->size; i++) {
        node_pos = hash->table[i].link.next;
        while (node_pos) {
            objs[j++] = node_pos->data;
            node_pos = node_pos->link.next;
        }
    }

    return objs;
}

void ST_hash_remove_all_objects (ST_hash_t *hash)
{
    int i = 0;
    struct _ST_hash_node *node = NULL,
                        *tmpptr = NULL;

    for (i=0; i<hash->size; i++) {
        node = hash->table[i].link.next;
        hash->table[i].link.next = NULL;

        while (node) {
            tmpptr = node->link.next;
            if (hash->hash_destroy) {
                hash->hash_destroy (node->data);
            }

            free (node);
            node = tmpptr;
        }
    }
    hash->num_objs = 0;
}

void ST_hash_release (ST_hash_t *hash)
{
    ST_hash_remove_all_objects (hash);
    free (hash->table);

    memset (hash, '\0', sizeof (ST_hash_t));
}
