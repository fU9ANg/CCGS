
#include "ccgs_singleton.h"

Singleton* Singleton::instance = NULL;

Singleton* Singleton::GetInstance () 
{
    if (NULL == instance)
    {
        instance = new Singleton (); 
    }

    return (instance);
}

Singleton::Singleton ()
{
    // TODO:
}
    
Singleton::~Singleton ()
{
    // TODO:
}
