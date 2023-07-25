#include <stdio.h>

int main(void)
{
	int n;
	long sum = 0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			sum++;
	}
	printf("%ld\n", sum);
	printf("2");
	return 0;
}