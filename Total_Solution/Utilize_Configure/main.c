#include <stdio.h>
#include <stdlib.h>
#include "BiscuitOS_Config.h"

int main()
{
    BiscuitOS_Parse_Configure();

    BiscuitOS_Show_Current_Configure();
    
    BiscuitOS_Release();    
}
