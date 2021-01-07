#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *thread_func(void *ID)
{
    printf("Hello SCR. Written by thread %lu\n", *(pthread_t *)(ID));
    pthread_exit(NULL);
}
int main()
{
    int error;
    pthread_t ID[5];
    for (int i = 0; i < 5; i++)
    {
        error = pthread_create(&ID[i], NULL, thread_func, &ID[i]);
        if (error)
        {
            exit(EXIT_FAILURE);
        }
    }
    pthread_exit(NULL);
}