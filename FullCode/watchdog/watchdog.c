/*
 * Watchdog demo code on userspace
 * (C) 2017.10 <buddy.zhang@aliyun.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>

#include <linux/watchdog.h>

#define MAX_FEED_CYCLE          10
#define MAX_WATCHDOG_TIMEOUT    20

/* watchdog node path  */
static char *wdt_path = NULL;
/* watchdog fd */
static int wdt_fd = -1;
/* feed frequency */
static int feed_cycle = 5;
/* timeout of watchdog */
static int wd_timeout = 10;
/* loop feed watchdog */
static int loop_feed = 1;
/* reboot_kill */
static int reboot_kill = 0;

/* Open watchdog */
void aup_open_watchdog(void)
{
    if (wdt_fd > 0) {
        printf("ERROR: watchdog has opended.\n");
        exit(1);
    }
    if (!wdt_path) {
        printf("ERROR: incorrect watchdog path.\n");
        exit(1);
    }
    /* open watchdog */
    wdt_fd = open(wdt_path, O_RDWR);
    if (wdt_fd < 0) {
        printf("ERROR: can't open %s\n", wdt_path);
        exit(1);
    }
}

/* Close watchdog */
void aup_close_watchdog(void)
{
    int ret;
    int option = 0x01;

    if (wdt_fd < 0) {
        printf("ERROR: watchdog has closed.\n");
        exit(1);
    }
    /* disable watchdog */
    ret = ioctl(wdt_fd, WDIOC_SETOPTIONS, &option);
    printf("Disable watchdog %d\n", ret);
    close(wdt_fd);
    wdt_fd = -1;
}

/* auto feed watchdog */
void aup_feed_watchdog_auto(void)
{
    int ret;
    int option = 0x02;

    if (wdt_fd < 0) {
        printf("ERROR: watchdog doesn't open.\n");
        exit(1);
    }
    /* re-enable watchdog */
    ret = ioctl(wdt_fd, WDIOC_SETOPTIONS, &option);
    printf("Enable watchdog %d\n", ret);
    while (loop_feed) {
        sleep(feed_cycle);
        ret = ioctl(wdt_fd, WDIOC_KEEPALIVE, 0);
        if (ret != 0) {
            printf("ERROR: failed to ioctl WDIOC_KEEPALIVE.\n");
            exit(1);
        }
    }
}

/* stop feed watchdog, the system will reboot when watchdog timeout */
void aup_stop_feed_watchdog(void)
{
    int ret;
    int option = 0x0;

    if (wdt_fd < 0) {
        printf("ERROR: watchdog doesn't open.\n");
        exit(1);
    }
    ret = ioctl(wdt_fd, WDIOC_SETOPTIONS, &option);
    printf("Stop watchdog %d\n", ret);
    loop_feed = 0;
}

/* exit this file */
void aup_exit(void)
{
    if (wdt_fd < 0) {
        printf("ERROR: watchdog doesn't open.\n");
        exit(1);
    }
    close(wdt_fd);
    wdt_fd = -1;
}

/* set watchdog timeout */
void aup_set_watchdog_timeout(int timeout)
{
    int ret;
    int option = 0x2;

    /* check if timeout is valid. */
    if (timeout < 0 || timeout > MAX_WATCHDOG_TIMEOUT) {
        printf("ERROR: invaild timeout!\n");
        exit(1);
    }

    /* check if watchdog node is valid. */
    if (wdt_fd < 0) {
        printf("ERROR: watchdog doesn't open.\n");
        exit(1);
    }

    /* re-enable watchdog */
    ioctl(wdt_fd, WDIOC_SETOPTIONS, &option);
    /* setup lower layer timeout register. */
    ret = ioctl(wdt_fd, WDIOC_SETTIMEOUT, &timeout);
    if (ret < 0) {
        printf("ERROR: Can't set timeout!\n");
        exit(1);
    }
    /* display newest timeout value */
    printf("Current watchdog timeout: %d\n", timeout);
}

/* set watchdog feed cycle */
void aup_set_feed_cycle(int cycle)
{
    int ret;
    int option = 0x2;

    if (wdt_fd < 0) {
        printf("ERROR: doesn't open watchdog.\n");
        exit(1);
    }

    /* check if cycle is valid */
    if (cycle < 0 || cycle > MAX_FEED_CYCLE) {
        printf("ERROR: invaild feed cycle.\n");
        exit(1);
    }
    if (cycle > wd_timeout) 
        printf("Note! feed cycle is small then watchdog timeout, "
               "The system will reboot after %d\n", cycle - wd_timeout);
    /* update feed cycle */
    feed_cycle = cycle;
    /* re-enable watchdog */
    ioctl(wdt_fd, WDIOC_SETOPTIONS, &option);
    /* display current feed cycle. */
    printf("Current feed cycle is %d\n", feed_cycle);
}

/* handle signal */
void aup_do_signal(int sig)
{
    switch (sig) {
    case SIGSTOP:
        /* CTRL Z */
        aup_close_watchdog();
        break;
    case SIGINT:
        /* CTRL C */
        aup_close_watchdog();
        break;
    case SIGQUIT:
        /* CTRL \ */
        aup_close_watchdog();
        break;
    case SIGKILL:
        /* force kill: kill -i pid */
        aup_stop_feed_watchdog();
        break;
    case SIGTERM:
        if (!reboot_kill) {
            /* Normal terminal: kill pid */
            aup_close_watchdog();
        } else {
            /* Force reoboot: kill pid */
            aup_stop_feed_watchdog();
        }
        break;
    default:
        printf("un-defined signal: %d\n", sig);
        break;
    }
}

/* initialize signal */
void aup_init_signal(void)
{
    signal(SIGSTOP, aup_do_signal);
    signal(SIGINT,  aup_do_signal);
    signal(SIGQUIT, aup_do_signal);
    signal(SIGKILL, aup_do_signal);
    signal(SIGTERM, aup_do_signal);
}

/* user help message */
void usage(const char *program_name) 
{
    printf("%s 1.0.0(2017-10-16)\n",program_name);
    printf("AuperaStor Watchdog\n");
    printf("Usage:%s [-t N[s]] [-T N[s]] [-F] DEV\n\n",
		program_name);
    printf("Periodically write to watchdog device DEV\n\n");
    printf("       -T N    Reboot after N seconds if not reset (default 60)\n");
    printf("       -t N    Reset every N seconds (default 30)\n");
    printf("       -F      Run in foreground\n");
    printf("       -r      Reboot system after timeout\n");
}

int main(int argc,char *argv[]) 
{
    int option_set_timeout = 0;
    int option_set_feedcycle = 0;
    int option_reboot = 0;
    int option_foreground = 0;
    char *option_timeout = NULL;
    char *option_feed_cycle = NULL;

    const char *short_opts = "h:T:t:r:F:";
    const struct option long_opts[] = {
	{"help", no_argument, NULL, 'h'},
	{"Foreground", no_argument, NULL, 'F'},
	{"reboot", no_argument, NULL, 'r'},
	{"Timeout", required_argument, NULL, 'T'},
	{"cycle", required_argument, NULL, 't'},
	{0,0,0,0}
    };
    int hflag = 0;
    int c;
    opterr = 0;
    
    /* get device name */
    if (argc == 1) {
        printf("ERROR:%s need DEV argument,as\n%s <DEV>\n",
               argv[0], argv[0]);
        exit(0);
    }
    /* get watchdog node path */
    wdt_path = argv[argc - 1];

    while((c = getopt_long(argc,argv,short_opts,long_opts,NULL)) != -1) {
	switch(c) {
        case 'h':
            hflag = 1;
            break;
        case 'T':
            option_timeout = optarg;
            option_set_timeout = 1;
            break;    
        case 't':
            option_feed_cycle = optarg;
            option_set_feedcycle = 1;
            break;
        case 'r':
            option_reboot = 1;
            reboot_kill = 1;
            break;
        case 'F':
            option_foreground = 1;
            break;
        case '?':
            if(optopt == 't' || optopt == 'T')
                printf("Error:option -'%c' requires an argument.\n", optopt);
            else if(isprint(optopt))
                printf("Error:unknow option '-%c'\n",optopt);
            else
                printf("Error:unknow option character '\\x%x\n'",optopt);
            return 1;
        default:
            abort();
        }
    }
    
    if(hflag) {
        usage(argv[0]);
	return 0;
    }

    if (!option_foreground)
        daemon(1, 1);

    /* open watchdog */
    aup_open_watchdog();

    /* initialize signal */
    aup_init_signal();

    /* setup watchdog timeout */
    if (option_set_timeout)
        sscanf(option_timeout, "%d", &wd_timeout);
    aup_set_watchdog_timeout(wd_timeout);

    /* setup watchdog cycle */
    if (option_set_feedcycle)
        sscanf(option_feed_cycle, "%d", &feed_cycle);
    aup_set_feed_cycle(feed_cycle);    

    /* feed watchdog */
    aup_feed_watchdog_auto();

    /* exit operation for watchodg */
    aup_exit();
    return 0;
}
