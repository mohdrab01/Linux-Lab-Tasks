/*
Q. Demonstrate INT handler Signals
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void INThandler(int);

void main(void){
        if (signal(SIGINT, SIG_IGN) != SIG_IGN)
                signal(SIGINT, INThandler);
        while(1)
                pause();
}

void INThandler(int sig){
        char c;
        signal(sig, SIG_IGN);
        printf("Ouch, Did you hit Ctrl+C?\nDo you really want to Quit [y/n]?\n");
        c = getchar();
        if (c=='y' || c=='Y')
                exit(0);
        else
                signal(SIGINT, INThandler);
}
