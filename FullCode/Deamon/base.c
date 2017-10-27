#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    if (daemon(1, 1) < 0) {
        printf("ERROR: deamon error.\n");
        exit(1);
    }
    while (1) {
        sleep(1);
        printf("Hello World.\n");
    }
    return 0;
}
