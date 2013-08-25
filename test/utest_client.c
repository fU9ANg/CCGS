
// for test

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
#define SERV_IP "127.0.0.1"
#define SERV_PORT 9999 
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
        sleep(1);
        printf("xxxx\n");

        for( i = 0; i< CON_NUM; ++i) {
//            send(cntFd[i], &x, sizeof(x), 0);
char s[] = "hello";
unsigned int x = sizeof (s);
ccgs_send_data (cntFd[i], ccgs_make_buffer (0, s, &x), x);
        }
   // }

    for( i = 0; i< CON_NUM; ++i) {
        close(cntFd[i]);
    }

    return 0;
}
