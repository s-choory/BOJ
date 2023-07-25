#include <stdio.h>

int main(void)
{	
	int A, B, V, location, n;

	scanf("%d %d %d", &A, &B, &V);
	n = (V-A)/(A-B);
	if((V-A)%(A-B) != 0)
		n++;
	if(V == A)
		location = 1;
	else
		location = n + 1;
	printf("%d", location);
	return 0;
}