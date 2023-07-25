#include <stdio.h>

int main(void)
{
	int arr1[100][100], arr2[100][100], arr3[100][100], n, m;

	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			scanf("%d", &arr1[i][j]);
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			scanf("%d", &arr2[i][j]);
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			arr3[i][j] = arr1[i][j] + arr2[i][j];
			printf("%d ", arr3[i][j]);
		}
		printf("\n");
	}
	return 0;
}
