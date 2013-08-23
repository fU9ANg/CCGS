#include <cstring>
#include <string.h>
#include <dlfcn.h>

#include "ccgs_manager.h"
#include "ccgs_common_buffer.h"
#include "ccgs_module.h"

/*
static char *getModuleInfo (char *modstr, unsigned int *mid)
{
    char *sep = strtok (modstr, ":");

    if (sep) {
        *sep = '\0';
        sep++;
        *mid = (unsigned int)atoi (sep);
    }

    return modstr;
}
*/

CModule::CModule ()
{
    this->m_handle = NULL;
    this->m_id     = 0;
    this->m_module = NULL;
}

CModule::~CModule ()
{
}

bool CModule::load (string name, unsigned int id)
{
    int ret;

    this->m_name = name;
    this->m_id   = id;
    this->m_handle = dlopen (name.c_str (), RTLD_LAZY);
    if (this->m_handle == NULL) {
        return false;
    }

    this->m_module = (ccgs_module_t*)dlsym (this->m_handle, CCGS_MODULE_SYMBOL);
    if (this->m_module == NULL) {
        dlclose (this->m_handle);
        return false;
    }
#ifdef DEBUG
    printf ("load module [%s:%d] successfully.\n", name.c_str (), id);
#endif
    
    ret = this->m_module->mod_load (this->m_module, id);
    if (ret < 0) {
        dlclose (this->m_handle);
        return false;
    }
    
    return true;
}

void CModule::unload ()
{
#ifdef DEBUG
    printf ("unload module [%s:%d] successfully.\n", this->m_name.c_str (), this->m_id);
#endif

    if (this->m_module->mod_unload) {
        this->m_module->mod_unload (this->m_module);
    }

    if (this->m_handle) {
        dlclose (this->m_handle);
    }

    this->m_handle = NULL;
    this->m_id = 0;
    this->m_module = NULL;
}





/*
 * return an index for hash table with module ID.
 */
static unsigned int hash_index_by_id (void *key)
{
    unsigned long ikey = (unsigned long)key;

    return (unsigned int)ikey;
}

/*
 * to find the module if a module ID already exists.
 */
static BOOL hash_compare_by_id (void *data, void *key)
{
    CModule *module = (CModule*)data;
    unsigned long ikey = (unsigned long)key;

    if (module->m_id == (unsigned int)ikey) {
        return TRUE;
    }

    return FALSE;
}

static void hash_destroy (void *data)
{
    CModule *module = (CModule*)data;

    module->unload ();
    delete module;
}

CModuleManager* CModuleManager::instance = NULL;

CModuleManager::CModuleManager ()
{
}

CModuleManager::~CModuleManager ()
{
    //TODO: add code here to destroy memories allocated before.
}

CModuleManager *CModuleManager::sharedInstance ()
{
    if (instance == NULL) {
        instance = new CModuleManager ();
    }

    return instance;
}

bool CModuleManager::init ()
{
    int ret;

    ret = ST_hash_init (&this->hash_by_id,
                        10,
                        hash_index_by_id,
                        hash_compare_by_id,
                        hash_destroy);

    if (ret < 0) {
        return false;
    }

    ret = ST_hash_init (&this->hash_buf_queue,
                        10,
                        hash_index_by_id,
                        hash_compare_by_id,
                        NULL);

    if (ret < 0) {
        return false;
    }
    return true;
}

void CModuleManager::uninit ()
{
    ST_hash_release (&this->hash_by_id);
    ST_hash_release (&this->hash_buf_queue);
}

bool CModuleManager::load (string modcfg)
{
    char *modstr = (char*)modcfg.c_str ();
    char *sepstr = NULL;
    char *modname = NULL;
    unsigned int modid = 0;
    CModule      *module = NULL;
    sepstr = strtok (modstr, ", ");
    do {
        modname = sepstr;
        sepstr = strrchr (sepstr, ':');
        if (sepstr) {
            *sepstr = '\0';
            modid   = (unsigned int)atoi (sepstr + 1);
        }

        module = new CModule ();
        if (!module->load (string (modname), modid)) {
            //TODO: write log if loaded module failed.
            this->unload ();
        } else {
            ST_hash_add_object (&this->hash_by_id, 
                                (void*)module, 
                                (void*)(unsigned long)modid);
        }
    } while ((sepstr = strtok (NULL, ", ")));

    return true;
}

void CModuleManager::unload ()
{
    int num = 0, i;
    void **mod_list = NULL;
    CModule *module = NULL;

    mod_list = ST_hash_list (&this->hash_by_id, &num);
    if (mod_list) {
        for (i=0; i<num; i++) {
            module = (CModule*)mod_list[i];
            ST_hash_remove_object (&this->hash_by_id, (void*)(unsigned long)module->m_id);
        }
        free (mod_list);
    }
}

CModule* CModuleManager::getModule (unsigned int id)
{
    return (CModule*)ST_hash_get_object (&this->hash_by_id, 
                                         (void*)(unsigned long)id);
}

void CModuleManager::removeModule (unsigned int id)
{
    ST_hash_get_object (&this->hash_by_id, (void*)(unsigned long)id);
}

void CModuleManager::addMBufferIntoQueue (void *buf, unsigned int mid)
{
    ST_hash_add_object (&this->hash_buf_queue, buf, (void*)(unsigned long)mid);
}

CQueue<void*> *CModuleManager::getMBufferQueue (unsigned int mid)
{
    void *saveptr = NULL,
         *databuf = NULL;
    CQueue<void*> *queue = new CQueue<void*>;

    databuf = ST_hash_next_object (&this->hash_buf_queue, (void*)(unsigned long)mid, &saveptr);
    while (databuf) {
        queue->InQueue (databuf);
        databuf = ST_hash_next_object (NULL, (void*)(unsigned long)mid, &saveptr);
    }

    return queue;
}

#include "ccgs_singleton.h"

ccgs_sockbuf_t *ccgs_sockbuf_alloc (unsigned int size)
{
    ccgs_sockbuf_t  *skbuf = NULL;
    CommBuf         *combuf= NULL;
    void            *bufptr= NULL;

    skbuf = (ccgs_sockbuf_t*)calloc (1, sizeof (ccgs_sockbuf_t));
    if (skbuf == NULL) {
        return NULL;
    }

    combuf = new CommBuf (size + SZCCGSHDR);
    bufptr = combuf->dataPtr;

    skbuf->intrptr= combuf;

    skbuf->header = (ccgs_header_t*)bufptr;
    skbuf->buffer = (char*)bufptr + SZCCGSHDR;
    skbuf->size   = size;
    skbuf->data_length = 0;

    memcpy (skbuf->header->identifier, CCGS_IDENTIFIER, 4);
    return skbuf;
}

void ccgs_sockbuf_free (ccgs_sockbuf_t *skbuf)
{
    CommBuf *combuf = (CommBuf*)skbuf->intrptr;

    if (combuf) {
        delete combuf;
    }

    free (skbuf);
}

int ccgs_add_into_queue (ccgs_sockbuf_t *skbuf, unsigned int mid)
{
#if 0
    if (skbuf->intrptr) {
        /*
         * the buffer will be released automatically,so
         * we don't release anymore here,just assign empty
         * pointer to it.
         */
        SINGLETON->sendQueue.InQueue ((CommBuf*)skbuf->intrptr);
        skbuf->intrptr = NULL;
    }
#endif
    if (skbuf) {
        SINGLETON->moduleManager.addMBufferIntoQueue ((void*)skbuf, mid);
    }
    return 0;
}

