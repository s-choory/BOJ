#include <stdio.h>

int main(void)
{
	int X, a = 0, b = 0, m=1, n=2;
	scanf("%d", &X);

	for(int i=0; i< X; i++)
	{
		if(a < m)
			a++;
		else if(a == m)
		{
			m = m + 2;
			while(a>1 && i<X)
			{
				a--;
				i++;
			}
		}
	}
	for(int i=0; i< X; i++)
	{
		if(b < n)
			b++;
		else if(b == n)
		{
			n = n + 2;
			while(b>1 && i<X)
			{
				b--;
				i++;
			}
		}
	}
	printf("%d/%d", a, b);
	return 0;
}