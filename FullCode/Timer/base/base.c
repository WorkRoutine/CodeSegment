/*
 * Timer
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

static int count = 0;
static struct itimerval oldtv;

void set_timer()
{
    struct itimerval itv;

    itv.it_interval.tv_sec = 1;
    itv.it_interval.tv_usec = 0;
    itv.it_value.tv_sec = 1;
    itv.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &itv, &oldtv);
    printf("A\n");
}

int main()
{
    set_timer();
    while (1);
    return 0;
}
