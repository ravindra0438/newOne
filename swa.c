#include<stdio.h>
#include<io.h>
void swap(int  a, int  b)
{
    int temp = (int )  a;
    a = b;
    b =temp;
    printf("after swapping a : %d b :%d ", a ,b);
}
int main()
{
    int a; 
    int  b;
    printf("enter a  value \n");
    scanf("%i", &a);
    fflush(stdin);
    printf("enter b value \n");
    scanf("%i", &b);
    fflush(stdin);
    swap(a, b); 
    int x = 0x10;
    printf("%x",x);

     int i = 1024;
     int c;
    for (; i; i >>= 1)
    { 
    printf("GeeksQuiz");
        c++;
    }
    printf("\n%d", c);
    return 0;

   
   
   return 0;
   
}
