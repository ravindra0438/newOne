#include<stdio.h>
#include<stdlib.h>
int Hcf(int dividend , int divisor)
{
   if(dividend%divisor ==0)
   {
    return divisor;
   }

   return Hcf(divisor, dividend%divisor);


}
int main()
{
    int a , b;
    printf("enter a \n");
    scanf("%d", &a);
    printf("enter b\n");
    scanf("%d",&b);
     int dividend =0, divisor=0;
    if(a>b)
    {
        dividend=a;
        divisor=b;
    }
    else
    {
        dividend=b;
        divisor=a;

    }
    if(dividend ==0 || divisor==0)
        {
                printf("invalid values is given");
		return -1;
        }

    int res= Hcf(dividend, divisor);
    printf("hcf of %d and %d is %d", dividend, divisor, res);
	return 0
}

