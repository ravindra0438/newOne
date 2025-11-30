#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"reverse.c"
int main()
{
    int number =121;
    int rev=reverse(number);
    if(number==rev)
    {
        printf("%d is a palindrome\n", number);
    }
    else
    {
        printf("%d is not a palindrome\n", number);
    }
}