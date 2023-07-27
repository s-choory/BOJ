#include <stdio.h>

int main(void)
{	
	while(1){
		int n, sum, cnt = 1, arr[100000] = { 0 };
		scanf("%d", &n);
		if(n < 0)
			break;
		for(int i=1; i<=n; i++)
		{
			if(n % i == 0)
			{
				arr[cnt] = i;
				cnt++;
			}
		}
		sum = 0;
		for(int i=1; arr[i] < n; i++)
			sum += arr[i];
		if(n == sum)
		{
			printf("%d =", n);
			for(int i =1; arr[i] < n; i++)
			{
				printf(" %d", arr[i]);
				if(n != arr[i+1])
					printf(" +");
			}
		}
		else if(n != sum)
			printf("%d is NOT perfect.", n);
		printf("\n");
	}
	return 0;
}