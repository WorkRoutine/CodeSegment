/*
 * The simple sample that uses thread basic opertion to use.
 * gcc x.c -lpthread -o a 
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

struct node {
    int number;
    struct node *next;
} *head = NULL;

/* Cleanup function. */
static void cleanup_handler(void *arg)
{
    printf("Cleanup handler of second thread.\n");
    pthread_mutex_unlock(&mtx);
}

/* Thread function */
static void *thread_func(void *arg)
{
    struct node *p = NULL;
    pthread_cleanup_push(cleanup_handler,p);

    while(1) {
	pthread_mutex_lock(&mtx);
	while(head == NULL) 
	    pthread_cond_wait(&cond,&mtx);
	p = head;
	head = head->next;
	printf("Go %d front of queue\n",p->number);
	free(p);
	pthread_mutex_unlock(&mtx);
    }
    pthread_cleanup_pop(0);
    return 0;
}

int main(int argc,char *argv[])
{
    pthread_t tid;
    int i;
    struct node *p;
    
    pthread_create(&tid,NULL,thread_func,NULL);

    for(i = 0 ; i < 10 ; i++) {
	p = malloc(sizeof(struct node));
	p->number = i;
	pthread_mutex_lock(&mtx);
	p->next = head;
	head = p;
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mtx);
	sleep(1);
    }
    printf("thread 1 wanna end the line.So cancel therad 2.\n");
    pthread_cancel(tid);
    pthread_join(tid,NULL);
    printf("All done -- exiting\n");
    return 0;
}
