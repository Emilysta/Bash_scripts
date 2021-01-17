#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#define NTHREADS 20
#define NPOINTS 3000
#define RADIUS 1
typedef struct thread_data
{
    float pi_value;
} thread_data;

void *thread_func(void *thread_arg)
{
    double point_x = 0;
    double point_y = 0;
    int points_in_circle = 0;
    thread_data *pi = (thread_data *)thread_arg;
    for (int i = 0; i < NPOINTS; i++)
    {                                 //all point are inside square
        point_x = drand48() * RADIUS; //drand48() points between <0,1)
        point_y = drand48() * RADIUS;
        if (sqrt(pow(point_x, 2) + pow(point_y, 2)) <= RADIUS)
        { //check if point is inside circle
            points_in_circle++;
        }
    }
    pi->pi_value = ((4.0 * points_in_circle) / NPOINTS);
    pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
    pthread_t threads[NTHREADS];
    int rc;
    long t;
    thread_data pi_arr[NTHREADS]; //array of pi values

    for (t = 0; t < NTHREADS; t++)
    {
        rc = pthread_create(&threads[t], NULL, thread_func, (void *)&pi_arr[t]);
        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    printf("Created %ld threads.\n", t);
    for (t = 0; t < NTHREADS; t++)
    {
        pthread_join(threads[t], NULL);
    } //wait for all to end
    float estimated = 0;
    for (t = 0; t < NTHREADS; t++)
    {
        printf("PI %f calculated by thread %ld\n", pi_arr[t].pi_value, t);
        estimated += pi_arr[t].pi_value;
    }
    estimated = estimated / NTHREADS;
    printf("PI estimated on values: %f\n", estimated);
    pthread_exit(NULL);
}
