#include "ccgs_module.h"

int main ()

{
    CModuleManager *m = new CModuleManager ();

    m->init ();
    if (!m->load ("sonto.so:12,wepone:45,good:56")) {

    }

    m->unload ();
    m->uninit ();
    delete m;
}
