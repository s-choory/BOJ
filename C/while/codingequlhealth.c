#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i+=4)
	{
		printf("long ");
	}
	printf("int");
	return 0;
}
