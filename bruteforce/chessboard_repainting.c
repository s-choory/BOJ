#include <stdio.h>

int main(void)
{
	int N, M, cnt, cnt2=65;
	char arr[50][50];

	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
			scanf(" %c", &arr[i][j]);
	}

	for(int k=0; k <= N-8; k++)
	{
		for(int l=0; l <= M-8; l++)
		{
			cnt = 0;
			for(int i=k; i < k+8 ; i++)
			{
				for(int j=l; j < l+8 ; j++)
				{
					if(arr[k][l] == 'W')
					{
						if(i%2 == 0)
						{
							if((l+j)%2 == 0 && arr[i][j] != 'W')
								cnt++;
							else if((l+j)%2 == 1 && arr[i][j] != 'B')
								cnt++;
						}
						else if(i%2 == 1)
						{
							if((l+j)%2 == 0 && arr[i][j] != 'B')
								cnt++;
							else if((l+j)%2 == 1 && arr[i][j] != 'W')
								cnt++;
						}
					}
					else if(arr[k][l] == 'B')
					{
						if(i%2 == 0)
						{
							if((l+j)%2 == 0 && arr[i][j] != 'B')
								cnt++;
							else if((l+j)%2 == 1 && arr[i][j] != 'W')
								cnt++;
						}
						else if(i%2 == 1)
						{
							if((l+j)%2 == 0 && arr[i][j] != 'W')
								cnt++;
							else if((l+j)%2 == 1 && arr[i][j] != 'B')
								cnt++;
						}
					}
				}
			}
			if(cnt < cnt2)
				cnt2 = cnt;
			if(64 - cnt < cnt2)
				cnt2 = 64 - cnt;
		}
	}
	printf("%d", cnt2);	
	return 0;
}