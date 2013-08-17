
#include <stdio.h>
#include "ccgs_thread_pool.h"
#include "ccgs_atomic.h"
#include "ccgs_mem_pool.h"
#include "ccgs_common_buffer.h"

#include "ccgs_manager.h"

// it's rock
int main (int argc, char** argv)
{
    CManager* process = NULL;

    if ((process = new CManager ()) == NULL)
    {
        cout << "ERROR: CManager is NULL" << endl;
        abort ();
    }

    process->Process (argc, argv);

    delete process;
    return 0;
}
