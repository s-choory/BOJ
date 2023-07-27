#include <stdio.h>

int main(void)
{
    int i, N, max, a;
    int arr[9];

    i = 0;
    while(i < 9)
    {
        scanf("%d", &N);
        arr[i] = N;
        i++;
    }
    i = 0;
    a = 1;
    max = arr[0];
    while(i < 9)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            a = i + 1;
        }
        i++;
    }
    printf("%d\n%d\n", max, a);
    return 0;
}