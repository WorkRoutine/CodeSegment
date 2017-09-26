# 1 "function.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "function.c"
int nCompletionStatus = 0;

float add(float x, float y)
{
 float z = x + y;
 return z;
}

float add_and_multiply(float x, float y)
{
 float z = add(x, y);
 z *= MULTIPLIER;
 return z;
}
