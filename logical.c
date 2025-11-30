#include<stdio.h>
#include<stdbool.h>
#define VAL 32
int main(  )
{
    int x =9;
    bool res= (x++ && x < 10);
    printf(" x : %d , res : %d\n", x, res);
    int k =1000000000;
    printf("%u \n", ~k);
     int i;
    
    i = 1, 2, 3;
    printf("%d\n", i);
      printf("%d", sizeof(printf("GeeksQuiz")));
      int a = 10, b = 20, c = 30; 
  if (c > b > a) 
    printf("TRUE"); 
  else
    printf("FALSE"); 
  char arr[] = "geeksquiz";
    *(arr + 0) &= ~VAL;
    *(arr + 5) &= ~VAL;
    printf("%s", arr);

    return 0;
}