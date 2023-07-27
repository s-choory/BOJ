#include <stdio.h>

int main(void)
{
    int N, X, i, k;

    scanf("%d %d", &N, &X);
    int arr[N];
    i = 0;
    while(i < N)
    {
        scanf("%d", &k);
        arr[i] = k;
        i++; 
    }
    i = 0;
    while(i < N)
    {
        if(arr[i] < X)
        printf("%d ", arr[i]);
        i++;
    }
    return 0;
}