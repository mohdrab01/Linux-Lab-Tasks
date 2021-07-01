/*
Q. Demonstrate raising a Signal handler
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void SIGhandler(int);

long pre_fact, i;

void main(void){
        long fact;
        signal(SIGUSR1, SIGhandler);
        for (pre_fact=i=1; ;i++, pre_fact=fact){
                fact = pre_fact*i;
                if (fact<0)
                        raise(SIGUSR1);
                else if (i%11==0){
                        printf("%ld = %ld\n",i,fact);
                        break;
                }

        }
}

void SIGhandler(int sig){
        printf("\nRecieved a SIGUSR1 signal %ld=%ld\n",i-1,pre_fact);
}
