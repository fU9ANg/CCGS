
#include "ccgs_send_task.h"

int SendTask::DoWork ()
{
#define MSG_HEADER_LEN 8
    char msg_head_str[MSG_HEADER_LEN];
    while (true)
    {
        CommBuf* p = NULL;
        if (SINGLETON->sendQueue.OutQueue (p, 3) != 0)
        {
            continue;
        }

        int fd = p->SocketFd ();

        if (fd <= 0)
        {
            cout << "[SEND] -- fd of buffer <= 0" << endl;
            SINGLETON->memPool.Free (p);
            continue;
        }

        (void) memset (msg_head_str, 0x00, MSG_HEADER_LEN);
        *(int *)msg_head_str = MSG_HEADER_LEN + p->UsedSize();
        *(int *)(msg_head_str + sizeof (int)) = 0x00;

        if (MSG_HEADER_LEN  != send_v (fd, msg_head_str, MSG_HEADER_LEN))
        {
            printf ("[ERROR]: send message header.\n");

        }

        cout << p->Data () << endl;
        cout << p->UsedSize () << endl;
        unsigned int send_len =  (unsigned int)send_v (fd, p->Data(), p->UsedSize());
        cout << "send len = " << send_len << endl;
        if (p->UsedSize() != send_len)
        {
            printf ("[ERROR]: send body of message.\n");
        }
#if 0
        // send fck message to clients
        int bytes_left = p->Size ();
        int written_bytes;
        char* ptr = (char*) p->Data ();
        while (bytes_left > 0)
        {
            written_bytes = send (fd, ptr, bytes_left, 0);
            if (written_bytes <= 0) {
                if (errno == EINTR) {
                    if (written_bytes < 0) {
                        written_bytes = 0;
                        cout << "EINTR......" << endl;
                        continue;
                    }
                }
                else if (errno == EAGAIN) {
                    if (written_bytes < 0) {
                        written_bytes = 0;
                        usleep (50);
                        cout << "EAGAIN......" << endl;
                        continue;
                    }
                }
                else {
                    break;
                }
            }
            bytes_left -= written_bytes;
            ptr += written_bytes;
        }

#endif

        //printf("Send data...finished. packetLength=%ld, from FD=[%d]\n", p->size(), fd);
        LOG(INFO) << "Send data ... finished. packet len=" << p->UsedSize() << ", from FD=" << fd << endl;

        p->Reset ();
        SINGLETON->memPool.Free (p);
    }

    return (0);
}

SendTask::SendTask () 
{
}

SendTask::~SendTask () 
{
}
