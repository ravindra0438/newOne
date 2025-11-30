#include<stdio.h>
int main()
{
    int x=0x1;
    char *ptr = (char *)&x;
    if(*ptr)
    {
        printf("little endian\n");
    }
    else
    {
        printf("Big endian");
    }


    char *str= "ravi";
    if(sizeof(str)==8)
    {
        printf("32 bit machine\n");
    }
    else{
        printf("64 bit machine\n");
    }
}