/*
Q. Copy one file content to other file
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        int f1,f2;
        char b[50];
        long int n;
        if (((f1 = open(argv[1], O_RDONLY)) == -1 || ((f2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0700)) == 1))){
                perror("Some Error in File");
                exit(1);
}
while((n=read(f1,b,50))>0){
        if(write(f2,b,n)!=n){
                perror("Some Error writing into File");
                exit(3);
        }
        if(n==-1){
                perror("Some Error Reading the File");
                exit(2);
        }
        close(f2);
        exit(0);
}
}
