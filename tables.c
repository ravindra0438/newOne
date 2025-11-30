#include<stdio.h>
int main()
{
    int n=5;
    int x =1;
    while(x<=n)
    {
        for(int i=1;i<10;i++)
        {
            printf("%3d ", i*x);
        }
        printf("\n");
        x++;
    }


    for(int i=1;i<10;i++)
    {
        if(i==5)
        
        {
            continue;
        }
        printf("%d ", i);
    }
}