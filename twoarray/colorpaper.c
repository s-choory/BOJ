#include <stdio.h>

int main(void)
{
	int n, x, y, a, arr[100][100] = { 0 }, cnt = 0;

	scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		scanf("%d %d", &x, &y);
		for(int j=0; j<10; j++)
		{
			for(int k=0; k<10; k++)
			{
				if(arr[x+j][y+k] == 1)
					cnt++;
				arr[x+j][y+k] = 1;
			}
		}
	}
	printf("%d", 100 * n - cnt);
	return 0;
}