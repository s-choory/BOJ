#include <stdio.h>
#include <math.h>

int is_prime(long long n){
	if (n <= 1) return 0;
	if (n == 2 || n == 3) return 1;
	if (n % 2 == 0 || n % 3 == 0) return 0;
	int i = 5;
	while (i <= sqrt(n)){
		if (n % i == 0 || n % (i+2) == 0)
			return 0;
		i += 6;
	}
	return 1;
}
int main(void)
{
	long long n, x;

	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%lld", &x);
		if(x <= 2)
			printf("2\n");
		else
		{
			if(x % 2 == 0)
				x++;
			while(is_prime(x) == 0)
				x += 2;
			printf("%lld\n", x);
		}
	}
	return 0;
}