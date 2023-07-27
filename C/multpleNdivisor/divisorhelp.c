#include <stdio.h>

int main(void)
{	
	int n, k, cnt = 1, arr[10000] = { 0 };

	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++)
	{
		if(n % i == 0)
		{
			arr[cnt] = i;
			cnt++;
		}
	}
	printf("%d", arr[k]);
	return 0;
}
