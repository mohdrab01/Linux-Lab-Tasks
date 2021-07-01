/*
Q. Demonstrate Inter Process Communication using Pipes
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(){
        char str[20];
        pid_t pid;
        int fd[2],n;
        pipe(fd);
        pid = fork();
        if(pid>0){
                close(fd[0]);
                write(fd[1],"IPC using Pipes",14);
        }
        else{
                close(fd[1]);
                n = read(fd[0],str,14);
                printf("%s",str);
        }
        return 0;
}
