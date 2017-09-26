# 1 "main.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "main.c"
# 1 "function.h" 1
# 11 "function.h"
float add_and_multiply(float x, float y);
# 2 "main.c" 2
extern int nCompletionStatus = 0;

int main(int argc, char *argv[])
{
 float x = 1.0;
 float y = 5.0;
 float z;

 z = add_and_multiply(x, y);
 nCompletionStatus = 1;

 return 0;
}
