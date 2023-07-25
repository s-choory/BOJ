#include <stdio.h>

int main(void)
{	
	int x, y, w, h, small;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	if(x <= y)
	{
		if(x <= w-x && x <= h-y)
		{
			printf("%d", x);
			return 0;
		}
	}
	if(x > y)
	{
		if(y <= h-y && y <= w-x)
		{
			printf("%d", y);
			return 0;
		}
	}
	if(w-x <= h-y)
		printf("%d", w-x);
	if(w-x > h-y)
		printf("%d", h-y);
	return 0;
}
