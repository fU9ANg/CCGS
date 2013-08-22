#ifndef _CCGS_MODULE_H
#define _CCGS_MODULE_H

#include <iostream>
#include <string>

#include "devel/CCGS_module.h"
#include "libst/SThash.h"

using namespace std;

class CModule {
public:
    CModule ();
    ~CModule ();
    bool load (string name, unsigned int id);
    void unload ();
public:
    //the module address.
    void *m_handle;

    //the module name
    string m_name;

    //the module ID.
    unsigned int m_id;

    /*
     * the m_module is related to the symbol from a 
     * loaded module. which is the entry of this module.
     */
    ccgs_module_t *m_module;
};


class CModuleManager {
private:
    ST_hash_t  hash_by_id;
    static class CModuleManager *instance;    
public:
    CModuleManager ();
    ~CModuleManager ();

    static class CModuleManager *sharedInstance ();
    bool init ();
    void uninit ();
    /*
     * Function: loadModules (string modules)
     * Description: the argument 'modules' is the type of stirng,
     *              the format is as below:
     *         mod_name1:id1,mod_name2:id2,...,mod_nameX:idX
     */
    bool load (string modules);
    void unload ();

    CModule *getModule (unsigned int id);
    void     removeModule (unsigned int id);
};

#define MODULE_MANAGER  CModuleManager::sharedInstance()
#endif
