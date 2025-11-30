#include<stdio.h>
int main()
{
    char name[5];
    printf("enter your name \n");
    fgets(name,5,stdin);
    printf("Welcome to %s", name);
    
}