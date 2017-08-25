#ifndef _ORANGEPI_CONFIG_H_
#define _ORANGEPI_CONFIG_H_

struct BiscuitOS_configure {
    char *String;
    int Int;  
};

/* Get OrangePi configure */
int BiscuitOS_Parse_Configure(void);

/* Release Resource */
void BiscuitOS_Release(void);

/* Show current camera configure */
void BiscuitOS_Show_Current_Configure(void);

char *OrangePi_Get_String(void);
int OrangePi_Get_Int(void);

#endif
