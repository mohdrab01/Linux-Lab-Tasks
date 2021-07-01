/*
Q. Copy file contents of a file to other file -- method 2
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
        char d[50];
        if (argc==3){
                bzero(d,sizeof(d));
                strcat(d,"cp ");
                strcat(d,argv[1]);
                strcat(d," ");
                strcat(d,argv[2]);
                system(d);
        }
        else{
                printf("\nInvalid No. of Arguments");
        }
        return 0;
}
