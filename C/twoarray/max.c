#include <stdio.h>

int main(void)
{
	int arr[9][9], max=0, a=0, b=0;

	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			scanf("%d", &arr[i][j]);
			if(arr[i][j] > max)
			{
				max = arr[i][j];
				a = i;
				b = j;
			}
		}
	}
	printf("%d\n%d %d", max, a+1, b+1);
	return 0;
}