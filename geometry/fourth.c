#include <stdio.h>

int main(void)
{
	int a, b, x, y, i, j, o, p;
	scanf("%d %d %d %d %d %d", &a, &b, &x, &y, &i, &j);
	if (x - a == 0)
		o = i;
	else if(i - x == 0)
		o = a;
	else if(i - a == 0)
		o = x;
	
	if (y - b == 0)
		p = j;
	else if(j - y == 0)
		p = b;
	else if(j - b == 0)
		p = y;
	printf("%d %d", o, p);
	return 0;
}
