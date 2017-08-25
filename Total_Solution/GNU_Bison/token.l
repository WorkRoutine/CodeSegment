%{
#include "y.tab.h"
%}
%%
"q" return STOP;
"Q" return STOP;
[0-9] return DIGIT;
[a-z] return LOWERCASELETTER;
[A-Z] return UPPERCASELETTER;
.     return OTHER;
%%
