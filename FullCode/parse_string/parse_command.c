/*
 * Parse command from string
 *
 * (C) 2717.12 <buddy.zhang@aliyun.com>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *set_cmd[] = {"set"};
char *get_cmd[] = {"get"};
char *log_on[]  = {"log", "on"};
char *log_off[] = {"log", "off"};

char *test_string = "get log   2023  off";

int parse_int(char *buffer)
{
    int start;
    int end = strlen(buffer);
    char *str = buffer;
    char native[20];

    for (start = 0; start < end; start++) {
        if (str[0] == ' ') {
            str++;
            continue;
        } else {
            char *sub;

            if ((sub = strchr(str, ' ')) != NULL) {
                int length = sub - str;
                /* Tail contain ' ' */

                strncpy(native, str, length);
                break;
            } else {
                strcpy(native, str);
                break;
            }
        }
    } 
    if (start == end)
        return -1;

    sscanf(native, "%d", &start);
    printf("Find %d\n", start);
    return start;
}

void parse_command(const char *buffer)
{
    char *str;
    char native[20];
    int length;

    /* command string */
    if ((strstr(buffer, set_cmd[0]) != NULL) ||
        (strstr(buffer, get_cmd[0]) != NULL)) {
        char *sub;

        /* Parse Log command */
        if ((str = strstr(buffer, log_on[0])) != NULL) {
            if ((sub = strstr(buffer, log_on[1])) != NULL) {
                /* log on*/
                str += strlen(log_on[1]) + 1;
                length = sub - str;
                strncpy(native, str, length); 
                native[length] = '\0';
                parse_int(native);
            } else if ((sub = strstr(buffer, log_off[1])) != NULL) {
                /* log off */
                str += strlen(log_off[1]) + 1;
                length = sub -str;
                strncpy(native, str, length);
                native[length] = '\0';
                parse_int(native);
            } else {
                printf("Unknown Command.\n");
                exit(1);
            }
        }
    }
}

int main(void)
{
    parse_command(test_string);
    return 0;
}
