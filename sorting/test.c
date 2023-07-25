#include <stdio.h>


int main(void)
{
    int n, k, arr[1000001] = { 0 }, arr2[1000001] = { 0 },flag, min=100000001, max=-100000001;

    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
		if(arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	k = 0;
	int a = min;
	for(int i = a; i <= (max); i++)
	{
		flag = 0;
		for(int j=0; j<n; j++)
		{
			if(arr[j] == min)
			{
				arr2[j] = k;
				flag = 1;
			}
		}
		if(flag == 1)
			k++;
		min++;
	}

    for(int i=0; i<n; i++)
        printf("%d ", arr2[i]);
}