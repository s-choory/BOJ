#include <stdio.h>

int main(void)
{
	int n, m, jud, arr[10000] = { 0 }, sum=0, minarr=0;

	scanf("%d %d", &m, &n);
	for(int i = m; i <= n; i++)
	{
		arr[i] = i;
		jud = 0;
		for (int j=1; j<=arr[i]; j++)
		{
			if (arr[i] == 1)
				break;
			if (arr[i] % j == 0)
				jud++;
		}
		if(jud == 2)
		{
			sum += arr[i];
			if(minarr == 0)
				minarr = arr[i];
		}
	}
	if(sum == 0)
		printf("-1");
	else
		printf("%d\n%d", sum, minarr);
	return 0;
}
