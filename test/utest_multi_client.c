
// for test

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>
#include "../src/devel/CCGS_common.h"
#include "../src/ccgs_utils.h"
#define SERV_IP "192.168.0.254"
#define SERV_PORT 8888
#define CON_NUM 1 


int main(int argc, char* argv[]){
    int cntFd[CON_NUM] = {0};
    int i = 0;
    for( i = 0; i< CON_NUM; ++i) {
        cntFd[i] = socket(AF_INET, SOCK_STREAM, 0);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(SERV_IP);
    addr.sin_port = htons(SERV_PORT);

    for( i = 0; i< CON_NUM; ++i) {
        connect(cntFd[i], (struct sockaddr*)&addr, sizeof(struct sockaddr));
    }
    //while(1) {
        printf("xxxx\n");

        for( i = 0; i< CON_NUM; ++i) {
#if 0
               char echostr[] = "PING";

               ccgs_send_data (cntFd[i], 0, echostr, strlen (echostr));
#else

               // fill data and send packet to server for testing
               
               char teststring[100];
               char *pstr = &teststring[0];
               memset (teststring, 0x00, 100);

               struct ccgs_header* header;
           
               *(int *) (pstr) = sizeof (struct ccgs_header) + 8 + 5;
               *(int *) (pstr + sizeof (int)) = 100;
               header = (ccgs_header *) (pstr + sizeof (int) + sizeof (int));

               memcpy (header->identifier, CCGS_IDENTIFIER, 4);
               header->MID    = 0;
               header->status = 0;
               header->flags  = 0;
               header->TID    = 0;
               header->length = 5;

               memcpy (pstr + sizeof (int) + sizeof (int) + sizeof (struct ccgs_header), "ABCDE", 5);

               send_v (cntFd[i], teststring, sizeof (struct ccgs_header) + 13);

               getchar ();

               // recv packet.

               memset (teststring, 0x00, sizeof (teststring));

               recv_v (cntFd[i], teststring, 8);
               int len = *(int*) teststring;
               printf ("length = %d\n", *(int *)teststring);
               printf ("reservation = %d\n", *(int *)(teststring + 4));

               recv_v (cntFd[i], teststring, len - 8); 

               printf ("data=%s\n", teststring + sizeof (struct ccgs_header));

               getchar ();
#endif
        }
   // }

    for( i = 0; i< CON_NUM; ++i) {
        close(cntFd[i]);
    }

    return 0;
}
