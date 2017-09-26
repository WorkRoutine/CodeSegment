/*
 * Describe: 有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
 * Maintainer: Buddy <buddy.zhang@liyun.com>
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k;
    int total = 0;
    
    for (i = 1; i <= 4; i++) 
        for (j = 1; j <= 4; j++)
            for (k = 1; k <=4; k++) {
                printf("%d\n",(i * 100 + j * 10 + k));
                total += 1;
            }

    printf("Total: %d\n", total);
                
    return 0;    
}
