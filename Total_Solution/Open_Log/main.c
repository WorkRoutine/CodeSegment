/*
 * openlog: open the system log file.
 * syslog : write the message into log with different log level.
 * close  : close the log file.
 * You can see the message on /var/log/syslog
 */
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc,char *argv[])
{
    openlog("Test",LOG_CONS | LOG_PID,LOG_USER);
    syslog(LOG_INFO,"This is a message just for test");
    closelog();

    return 0;
}
