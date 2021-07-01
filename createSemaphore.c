/*
Q. Demonstrate the creation of a semaphore
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>

void main(){
        int semid;
        key_t key = (key_t)0x20;
        semid = semget(key,1,IPC_CREAT|0666);
        printf("semid = %d",semid);
}
