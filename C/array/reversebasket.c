#include <stdio.h>

int main(void)
{
    int N, M, i, a, b, tmp, m;

    scanf("%d", &N);
    int arr[100];
    i = 1;
    while (i <= N)
    {
        arr[i] = i;
        i++;
    }
    scanf("%d", &M);
    i = 1;
	tmp = 0;
    while (i <= M)
    {
        scanf("%d %d", &a, &b);
		while (a < b)
		{
			m = a;
			while (m < b)
        	{	
				tmp = arr[m];
				arr[m] = arr[m+1];
				arr[m+1] = tmp;
				m++;
			}
			b--;
		}
        i++;
    }
    i = 1;
    while (i <= N)
    {
        printf("%d ", arr[i]);
        i++;
    }
    return 0;
}