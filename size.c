#include<stdio.h>
int x = 20;
int j= 10000;
int v;
extern int k;
int main()
{
    int x = 10;
    double d = 11.5;

    int z;
    printf("%zu \n ", sizeof(x));
    printf("%zu \n", sizeof(d));
    printf("%zu\n", sizeof(15LL));
    printf("%zu\n", sizeof(13.6f));
    printf("%zu\n", sizeof((x+10)));
    printf("%zu\n", sizeof(x++));

    printf("z === %d \n", z);
    printf("v=== %d\n", v);
    {
        //int x =30;
        printf("x : %d ",x);
    }
    printf("k --- %d", k);
    
    return 0;
}
int k = 143;