#include<stdio.h>
#include<stdlib.h>
int main()
{
    char *ptr=  "raveendra";
    int p = 0x12345678; // lsb stores in memory first we can call it as little endian.

    char *ch = (char *)&p;

    if(*ch ==0x78)
    {
        printf("little endian\n");
    }
    printf("%x %x %x %x ", ch[0], ch[1], ch[2],ch[3]);
   
}