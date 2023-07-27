#include <stdio.h>

int main(void)
{
    int N, M, i, a, b, c;

    scanf("%d", &N);
    int arr[N];
    i = 1;
    while (i <= N)
    {
        arr[i] = 0;
        i++;
    }
    scanf("%d", &M);
    i = 1;
    while (i <= M)
    {
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        while(a <= b)
        {
            arr[a] = c;
            a++;
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