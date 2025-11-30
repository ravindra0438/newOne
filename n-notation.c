#include<stdio.h>
int main()
{
    int x;
    printf("abc %ncd", &x);
    printf("\nthe value of x is %d\n", x);
    printf("\"Raveendra\"");
    int y= printf("Ravi");
    printf("%d\n",y);
    printf("%d", printf("%d", 1234));
        int a = 10, b = 20, c;
    c = scanf("%d %d", &a, &b);
    printf("%d %d %d\n", a, b, c);

}