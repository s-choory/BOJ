#include <stdio.h>

int main(void)
{
	int tmp, sum = 0, arr[3] = { 0 };
	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
	for(int i=0; i < 2; i++)
	{
		for(int j=0; j<2; j++)
		{
			if(arr[j] > arr[j+1])
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
	if(arr[2] >= arr[0] + arr[1])
		sum = (arr[0] + arr[1]) * 2 - 1;
	else
		sum = arr[0] + arr[1] + arr[2];
	printf("%d", sum);
	return 0;
}