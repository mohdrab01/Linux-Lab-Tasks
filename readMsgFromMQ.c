/*
Q. Read msg from MQ
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

struct msg{
        long type;
        char text[252];
}msg;

void main(){
        int msqid;
        msqid = msgget((key_t)10,IPC_CREAT|0666);
        printf("qid recieved = %d\n",msqid);
        msgrcv(msqid,&msg,255,6,IPC_NOWAIT);
        printf("%s",msg.text);
}
