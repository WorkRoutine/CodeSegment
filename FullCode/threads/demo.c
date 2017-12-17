/*
 * Interactive demo
 *
 * (C) 2017.12 <buddy.zhang@aliyun,com>
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_t txp;
pthread_t rxp;

/* TX handler */
void *do_tx(void *arg)
{
    while (1) {
        printf("%s Hello\n", __func__);
        sleep(1);
    }
}

/* RX handler */
void *do_rx(void *arg)
{
    while (1) {
        printf("%s Hello\n", __func__);
        sleep(2);
    }
}

int main(void)
{
    int ret;

    /* Create TX thread */
    ret = pthread_create(&txp, NULL, do_tx, NULL);
    if (ret) {
        fprintf(stderr, "Unable to create TX pthread.\n");
        return -1;
    }
    /* Create RX thread */
    ret = pthread_create(&rxp, NULL, do_rx, NULL);
    if (ret) {
        fprintf(stderr, "Unable to create RX pthread.\n");
        return -1;
    }

    /* Hold Father process */
    while (1);

    return 0;
}
