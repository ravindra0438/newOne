#include <stdio.h>

int isPrime(int n){
	int flag=1;
	for(int i=2; i*i<=n; i++){
		if(n%i==0){
			flag=0;
		}
	}
	if(flag) return 1;
	return 0;
}

int primeFactors(int n)
{
    for(int i = 2; i <= n; i++){
        if(isPrime(i) == 1)
        {
            int x = i;
            while(n % x == 0)
            {
                printf("%d ", i);
                x = x * i;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    primeFactors(n);
}