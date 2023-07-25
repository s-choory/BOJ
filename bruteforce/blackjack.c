#include <stdio.h>

int main(void)
{
	int N, M, a=0, arr[103] = { 0 }, sum[100000] = { 0 }, b = 0;

	scanf("%d %d", &N, &M);

	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]);
	
	for(int i=0; i<N; i++)
	{
		for(int j=i+1; j<N; j++)
		{
			for(int k=j+1; k<N; k++)
			{
				sum[a] = arr[i]+arr[j]+arr[k];
				if(sum[a] > b && sum[a] <= M)
					b = sum[a];
				a++;
			}
		}
	}
	printf("%d", b);
	return 0;
}