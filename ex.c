
# include <string.h>
#include<stdio.h>


int inc(int a)
{
 printf("\nInside inc() %d\\n",a);
 if(a==100 || a==0)
 {
    return 0;
 }

int sum= inc(a+1);
 return inc(a-1);
}

int main()
{
inc(1);





 return 0;
}

