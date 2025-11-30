#include<stdio.h>
int main()
{
    int x=124;
    char g[10]="gfg";
    float z =1.2;
    printf("%5d\n%5s\n%f\n", x,g,z);
    printf("%05d", x);
    printf("\n%+5d", x);
    return 0;
}