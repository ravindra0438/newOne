#include<stdio.h>
int sum(int ,int);
int main()
{
    int x = sum(10,5);
    printf("sum : %d",x);
    return 0;
}
int sum(int x, int y)
{
    return x+y;
}
    