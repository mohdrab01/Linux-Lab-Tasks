/*
Q. Demonstrate Orphan process
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
        int pid = fork();
        if (pid > 0)
                printf("In Parent Process\n");
        else if (pid ==0){
                sleep(30);
                printf("In child process\n");
        }
        return 0;
}
