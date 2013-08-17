
#include "ccgs_recv_task.h"

RecvTask::RecvTask ()
{
}

RecvTask::~RecvTask ()
{
}

int RecvTask::DoWork ()
{
    while (true)
    {
        CommBuf* p = NULL;
        if (SINGLETON->recvQueue.OutQueue (p, 3) != 0)
        {
            continue;
        }

        if (p == NULL)
        {
            cout << "ERROR: p==NULL in RecvTask::work()" << endl;
            return (0);
        }
#if 0
        MSG_HEAD* head = (MSG_HEAD*) p->ptr();
        if (head != NULL)
        {
            debugProtocol (p);
            cout << "recvTask: cType=" << head->cType << endl;
            handlefunc pfun = CHandleMessage::getHandler (head->cType); 
            if (NULL == pfun)
            {
                printf ("ERROR: the pointer of callback, cType=[%d]\n", head->cType);
                p->reset ();
                SINGLE->bufpool.free (p);
                continue;
            }
            pfun (p);
        }
#endif
    }
    return (0);
}
