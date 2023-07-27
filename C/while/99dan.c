#include <stdio.h>

int main(void)
{
    int i, N;

    scanf("%d", &N);
    i = 1;
    while(i <= 9)
    {
        printf("%d * %d = %d\n", N, i, N*i);
        i++;
    }
    return 0;
}