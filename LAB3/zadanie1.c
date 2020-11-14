#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <ucontext.h>
#include <stdlib.h>


int main(){

    struct timespec timer1;
    timer1.tv_sec = 0;
    timer1.tv_nsec =100000000L;
    printf("%ld\n",(long)getpid());
    int i=0;
    while(1){
        i++;
        nanosleep(&timer1,NULL);
    }
    return 0;    
}