#include <stdio.h>
#include <time.h>

int main(){

    while(1){
        printf("Mój numer pid: %ld\n",(long)getpid());
        sleep(1);
    }
    return 0;
}