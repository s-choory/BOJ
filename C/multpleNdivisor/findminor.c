#include <stdio.h>

int main(void)
{
	int n, jud, arr[100], cnt=0;

	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
		jud = 0;
		for(int j=1; j<=arr[i]; j++)
		{
			if (arr[i] == 1)
				break;
			if (arr[i] % j == 0)
				jud++;
		}
		if(jud == 2)
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}
