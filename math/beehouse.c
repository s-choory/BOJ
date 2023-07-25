#include <stdio.h>

int main(void)
{
	int n, k = 1, max = 1;
	scanf("%d", &n);

	while(n > max)
	{
		k++;
		max = 3 * k * (k -1) + 1;
	}
	printf("%d", k);
	return 0;
}