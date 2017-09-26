/*
 * Thread demo code
 *
 * (C) 2017.09 <buddy.zhang@aliyun.com>
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void do_pthread1(char *ptr)
{
    int retval;
    int id;

    id = pthread_self();
    printf("%s ID %#x\n", ptr, id);
    pthread_exit(&retval);
}

int main(void)
{
    pthread_t thread1, thread2;
    char *msg1 = "You know nothing.\n";
    char *msg2 = "You know everything.\n";

    pthread_create(&thread1, NULL, (void *)(&do_pthread1), (void *)msg1);
    pthread_create(&thread2, NULL, (void *)(&do_pthread1), (void *)msg2);
    sleep(1);
    return 0;
}
