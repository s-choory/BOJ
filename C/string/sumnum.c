#include <stdio.h>

int main(void)
{
	int n, i, sum = 0;
	char ch;

	scanf("%d", &n);
	i = 0;
	while(i < n)
	{
		scanf(" %c", &ch);
		sum += ch - 48;
		i++;
	}
	printf("%d", sum);
	return 0;
}