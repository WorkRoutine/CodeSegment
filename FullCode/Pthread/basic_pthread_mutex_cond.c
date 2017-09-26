/*
 * Basic way to use thread mutex and condition.
 * gcc main.c -lpthread -o a
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int main(int argc,char *argv[])
{
    /* Pthread condition value */
    pthread_cond_t cv;
    /* Or pthread condition value */
    pthread_cond_t cv2 = PTHREAD_COND_INITIALIZER;
    /* Pthread mutex lock value */
    pthread_mutex_t mutex;

    /* Initialize the pthread mutex lock */
    pthread_mutex_init(&mutex,NULL);
    /* Initialze the pthread condition */
    pthread_cond_init(&cv,NULL);

    /* destory a pthread condition */
    pthread_cond_destroy(&cv);
    /* destory a pthread mutex lock */
    pthread_mutex_destroy(&mutex);
    return 0;
}
