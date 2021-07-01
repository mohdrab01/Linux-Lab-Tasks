/*
Q. WACP to kill a signal
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main(void){
        pid_t pid, *ShmPTR;
        key_t MyKey;
        int ShmID;
        char c;

        MyKey = ftok("./",'a');
        ShmID = shmget(MyKey, sizeof(pid_t), IPC_CREAT|0666);
        ShmPTR = (pid_t *) shmat(ShmID, NULL, 0);
        pid = *ShmPTR;
        shmdt(ShmPTR);
        while(1){
                printf("(Press i for Interrupt or k for Kill)?\n");
                c = getchar();
                if (c=='i' || c=='I'){
                        kill(pid, SIGINT);
                        printf("SIGKILL signal has been sent!\n");
                }
                else if (c=='k' || c=='K'){
                        printf("About to send SIGQUIT signal!\n");
                        kill(pid, SIGQUIT);
                        exit(0);
                }
                else
                        printf("Wrong Key Press (%c). Try again!\n",c);
        }
}
