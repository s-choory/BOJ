#include <stdio.h>

int main(void)
{
    int N, i, k, max, min;

    scanf("%d", &N);
    int arr[N];
    i = 0;
    while(i < N)
    {
        scanf("%d", &k);
        arr[i] = k;
        i++; 
    }
    max = arr[0];
    min = arr[0];
    i = 1;
    while(i < N)
    {
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
        i++;
    }
    printf("%d %d", min , max);
    return 0;
}