#include<stdio.h>
#include<stdlib.h>
int reverse(int number);
int reverse(int number)
{
    int temp=number;
    int rev=0;
    while(temp>0)
    {
        rev= rev*10+temp%10;
        temp= temp/10;
    }
    return rev;
}
