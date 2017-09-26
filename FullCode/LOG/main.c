#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG(...) { \
    char _bf[1024] = {0};  \
    snprintf(_bf,sizeof(_bf) - 1,__VA_ARGS__);   \
    fprintf(stderr,"%s",_bf); \
    syslog(LOG_INFO,"%s",_bf);  \
}

#define BUG(...) printf("%s",__VA_ARGS__)

int main(int argc,char *argv[])
{
    BUG("Full test\n");
     
    return 0;
}
