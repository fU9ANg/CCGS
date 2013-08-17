
#ifndef CCGS_RECV_TASK_H_
#define CCGS_RECV_TASK_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#include "ccgs_thread_task.h"
#include "ccgs_utils.h"
#include "ccgs_singleton.h"
#include "ccgs_common_buffer.h"

class RecvTask: public threadTask
{
    public:
        RecvTask ();
        ~RecvTask ();
        virtual int DoWork ();
};

#endif
