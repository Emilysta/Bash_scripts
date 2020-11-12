#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <ucontext.h>
#include <stdlib.h>
int catched = 0;

void catch(int sig, siginfo_t *sig_i, ucontext_t *u){

    if(sig==14){
        printf("złapaliśmy sigalarm\n");
        exit(1); //zakonczenie dzialania
    }
    if(sig==12){
        printf("złapaliśmy sigusr2\n");
    }
    if(sig==15){
        printf("złapaliśmy sigterm\n");
        catched = 1;
    }
}
int main(){

    sigset_t signal_set;
    sigemptyset(&signal_set);
    sigaddset(&signal_set,SIGUSR2);
    sigaddset(&signal_set,SIGTERM);
    sigaddset(&signal_set,SIGALRM);

    sigprocmask(SIG_UNBLOCK,&signal_set,NULL); //przechwytywanie zestawu sygnałów

    struct sigaction act;
    act.sa_handler = catch;
    act.sa_flags = SA_SIGINFO;

    sigaction(SIGALRM,&act,0);
    sigaction(SIGTERM,&act,0);
    sigaction(SIGUSR2,&act,0);
    sigignore(SIGUSR1); //ignorowanie sygnału SIGUSR1
    
    struct sigaction act2;
    act2.sa_flags = SA_SIGINFO;

    struct timespec timer1;
    timer1.tv_sec = 0;
    timer1.tv_nsec =100000000L;
    int counter=0;
    printf("%ld\n",(long)getpid());
    int i=0;
    while(1){
        i++;
        nanosleep(&timer1,NULL);
        if(catched==1){
            sigignore(SIGTERM);
            counter++;
            if(counter==100){
                counter=0;
                sigaction(SIGTERM,&act2,0); //przywrócenie pierwotnego działania czyli zakończenie działania programu
                //sigaction(SIGTERM,&act,0); //przywrócenie do łapania sygnału 
                catched=0;
                printf("zakonczono\n");
            }
        }
    }
}