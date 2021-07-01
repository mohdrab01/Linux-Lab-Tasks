/*
Q. WACP To create MSG QUEUE and send msg to Queue
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
        int msqid, len;
        msqid = msgget((key_t)10,IPC_CREAT|0666);
        printf("qid = %d\n",msqid);
        msg.type = 6;
        strcpy(msg.text,"Example for MSG QUEUE...");
        len = strlen(msg.text);
        if (msgsnd(msqid,&msg,len,0) == 1){
                printf("Error in writing message to queue...\n");
                exit(0);
        }
        printf("Message placed into queue successfully...\n");
}
