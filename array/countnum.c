#include <stdio.h>

int main(void)
{
    int n, i, j, k, cnt;
    int arr[100];

    scanf("%d", &n);
    i = 0;
    while (i < n)
    {
        scanf("%d", &j);
        arr[i] = j;
        i++;
        j = 0;
    }
    i = 0;
    scanf("%d", &k);
    cnt = 0;
    while (i < n)
    {
        if (arr[i] == k)
        cnt++;
        i++;
    }
    printf("%d", cnt);
    return 0;
}