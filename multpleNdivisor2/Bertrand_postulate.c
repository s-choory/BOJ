#include <stdio.h>
#include <math.h>

int is_prime(int n){
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
    int n, max;
    while(1)
    {
        int count = 0;
        scanf("%d", &n);
        max = 2*n;
        if(n == 0)
            break;
        else if(n == 1 || n == 2)
            printf("1\n");
        else
        {
            n++;
            while(n <= max)
            {
                if(n % 2 == 0)
                    n++;
                while(is_prime(n) == 0)
                    n += 2;
                if(n <= max)
                    count++;
                n++;
            }
            printf("%d\n", count);
        }
    }
    return 0;
}