#include <stdio.h>

int main(void)
{
	int n;
	long sum=0;
	scanf("%d", &n);
	for(int i=0; i< n-1; i++)
	{
		for(int j=i+1; j<n; j++)
			sum++;
	}
	printf("%ld\n", sum);
	printf("%d", 2);
	return 0;
}
