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
	int x, y;

	scanf("%d %d", &x, &y);
    if(x == 1)
        x++;
	while(x <= y)
	{
		if(x == 2)
			printf("2\n");
		else
		{	
			if(x % 2 == 0)
				x++;
			while(is_prime(x) == 0)
				x += 2;
            if(x <= y)
			    printf("%d\n", x);
		}
		x++;
	}
	return 0;
}