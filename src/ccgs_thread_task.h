
#ifndef _CCGS_THREAD_TASK_H_
#define _CCGS_THREAD_TASK_H_

#include "glog/logging.h"

#include "ccgs_common_buffer.h"
#include "ccgs_db_connection.h"

#define CT_FLAGS 0
#define ST_FLAGS 1

class threadTask
{
    public:
        threadTask () : exitOfFinish (true)
        {
            // TODO:
        }
        virtual ~threadTask() {}
        virtual int DoWork() = 0;

        bool exitOfFinish;
        
    private:
        // TODO:
};

#endif  //_CCGS_THREAD_TASK_H_
