#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n ; i++)
	{
		for(int j=2; j <= n ; j++)
		{
			if(n == 1)
				break;
			if(n % j == 0)
			{
				printf("%d\n", j);
				n = n / j;
				j = 1;
			}
		}
	}
	return 0;
}