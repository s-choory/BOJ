#include <stdio.h>

int main(void)
{
    int n, cnt = 0;

    scanf("%d", &n);
    for(int i = 1; i * i <= n; i++)
        cnt++;
    printf("%d", cnt);
    return 0;
}