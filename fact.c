#include<stdio.h>
unsigned long long int fact(long long int n)
{
    if(n ==0 || n==1)
    {
        return 1;
    }
    return n* fact(n-1);
}
int main()
{
    printf("enter the number \n");
    unsigned long long int n;
    scanf("%llu",&n);
    printf("factorial of %llu is %llu", n, fact(n));
}