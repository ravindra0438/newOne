#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *arr;
    int i, n;
    n=5;

    arr = calloc(n, sizeof(int));
    for(int i=0;i<n;i++)
    {
        arr[i] = i;

    }
    for(int i=0;i<n;i++)
    {
         printf("%d ", arr[i]);

    }
    n =100;
    arr = realloc(arr , n*sizeof(int));
   
    for(int i=5;i<n;i++)
    {
        arr[i]=i;
    }
printf("\n");
    for(int i=0;i<n;i++)
    {
         printf("%d ", arr[i]);

    }
}
    