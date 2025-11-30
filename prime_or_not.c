#include<stdio.h>
#include<conio.h>

int main()
{
    printf("enter number to check prime or not \n");
    int number;
   
   
    for (int p=3;p<100;p++)
    {
        number =p;
         int i=2;
    int flag=0;
    while(i<number)
    {
        if(number%i==0)
        {
            printf("%d is not a prime number \n", number);
            flag=1;
            break;
        }
        i++;
    }
    if(flag== 0)
    {
    printf("%d is a prime number\n", number);
    }
}

    char ch='A';
    printf("the ascii value of %c is %d\n",ch, ch );
}