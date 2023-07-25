#include <stdio.h>

int main(void)
{
    int N, M, i, a, b, tmp;

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
        scanf("%d", &a);
        scanf("%d", &b);
        tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;		
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