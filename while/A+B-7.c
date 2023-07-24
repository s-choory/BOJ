#include <stdio.h>

int main(void)
{
    int N, A, B, i;

    scanf("%d", &N);
    i = 1;
    while(i <= N)
    {
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d\n", i, A+B);
        i++;
    }
    return 0;
}