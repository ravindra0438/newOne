#include<stdio.h>
#include<stdlib.h>
int * getArray(int n)
{

    int *ptr= (int *) malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        //ptr[i] =i;
        *(ptr+i) =i;
        *(ptr+i) = (i*10)+5;
    }
    
    return ptr;
}
int main()
{   
    int n= 5;
    int *arr = getArray(5);
    
    for(int i=0;i<n;i++)
    {
        printf("%d ", *(arr+i));
    }
    free(arr);
}