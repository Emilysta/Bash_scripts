#include <stdio.h>

int main(){

    printf("Mój pid: %ld\n",(long)getpid());
    while(1){
        printf("Hello\n");
        sleep(1);
    }
    return 0;
}