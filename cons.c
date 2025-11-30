#include<stdio.h>
#include"val.c"
int main()
{

    printf("%d \n", f);
    for (int i=0;i<5;i++)
    {
       int x = func();
       printf("x = %d\n", x);
    }
    const int *x;
    printf (" address of an x %p\n",&x);
    x = 10;
    x =200;
    printf (" address of an x %p\n",&x);
    printf("%d ", x);
}