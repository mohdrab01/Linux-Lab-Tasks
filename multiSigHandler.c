/*
Q. Demonstrate multiple Signal Handler
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_i 10000
#define MAX_j 20000
#define MAX_SEC (2)

void INThandler(int);
void ALARMhandler(int);

int SEC, i, j;

void main(int argc, char *argv[]){
        long sum;
        SEC = abs(atoi(argv[1]));
        signal(SIGINT, INThandler);
        signal(SIGALRM, ALARMhandler);
        alarm(SEC);
        for (i=1;i<=MAX_i;i++){
                sum=0;
                for (j=1;j<=MAX_j;j++){
                        sum+=j;
                }
        }
        printf("\nComputation is Done!\n");
}

void INThandler(int sig){
        char c;
        signal(SIGINT, SIG_IGN);
        signal(SIGALRM, SIG_IGN);
        printf("INT handler: i=%d and j=%d\n",i,j);
        printf("INT handler: Want to quit? [y/n]\n");
        c = tolower(getchar());
        if (c=='y'){
                printf("INT handler: done\n");
                exit(0);
        }
        signal(SIGINT, INThandler);
        signal(SIGALRM, ALARMhandler);
        alarm(SEC);
}

void ALARMhandler(int sig){
        signal(SIGINT, SIG_IGN);
        signal(SIGALRM, SIG_IGN);
        printf("ALARM handler: alarm signal received\n");
        printf("ALARM handler: i=%d and j=%d\n",i,j);
        alarm(SEC);
        signal(SIGINT, INThandler);
        signal(SIGALRM, ALARMhandler);
}
