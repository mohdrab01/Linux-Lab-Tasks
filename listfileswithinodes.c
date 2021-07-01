/*
Q. List the files in the current directory along with their inode values
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
        char d[50];
        if (argc==2){
                bzero(d,sizeof(d));
                strcat(d,"ls ");
                strcat(d,"-i ");
                strcat(d,argv[1]);
                system(d);
        }
        else{
                printf("\nInvalid No. of Arguments");
        }
        return 0;
}
