#include <stdio.h>

int main(void)
{
	while(1)
	{
		int a, b, c, tmp, arr[3] = { 0 };
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
		if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			break;
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
		a = arr[0];
		b = arr[1];
		c = arr[2];
		if(c >= a+b)
			printf("Invalid\n");
		else
		{
			if(a == 0 && b == 0 && c == 0)
				break;
			if(a == b && b == c)
				printf("Equilateral\n");
			else if(a == b || b == c || a == c)
				printf("Isosceles\n");
			else if(a != b && b != c && a != c)
				printf("Scalene\n");
		}
	}
	return 0;
}
