#include<stdio.h>
void swap(int * a, int * b)
{
    int *temp = (int *) * a;
    *a = *b;
    b =temp;
}

int main()
{
    int a =10;
    int b = 20;
    swap(&a, &b);
    printf(" after swapping a : %d b: %d ", a ,b);
    #include <stdio.h>

int i;
for ( i=0; i<5; i++ )
{
   int i = 10;
   printf ( "%d ", i );
   i++;
}
}
