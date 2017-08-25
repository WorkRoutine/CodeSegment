#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void show_name(void);

int main(int argc, char *argv[])
{
    printf("Hello World\n");
    show_name();
    
    return 0;    
}
