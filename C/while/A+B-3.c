#include <stdio.h>

int main(void)
{
    int N, A, B;

    scanf("%d", &N);
    while(N > 0)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", A+B);
        N--;
    }
    return 0;
}