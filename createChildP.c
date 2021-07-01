/*
Q. Create a child process 
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void forkEx(){
        if (fork()==0){
                printf("Hello from child!\n");
        }
        else{
                printf("Hello from Parent!\n");
        }
}
int main(){
        forkEx();
        return 0;
}
