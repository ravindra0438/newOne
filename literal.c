#include<stdio.h>
int main()
{
    float a = 10.5f;
    double b = 10.515;
    long double c = 10.515l;
    float d = 2.1e4f;
    double e = 200.1e-80;
    double f= 0x1A.1p2;
    printf("%g\n",d);
    printf("%Lg\n",c);
    printf("%g\n %g\n %Lg\n %g\n %g\n %g\n", a , b,c,d,e,f);
    return 0;
}