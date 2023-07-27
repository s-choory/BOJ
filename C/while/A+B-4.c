#include <stdio.h>

int main(void)
{
    int i, A, B;

    i = 1;
    while(scanf("%d %d", &A, &B) != EOF)
    {
        printf("%d\n", A+B);
    }
    return 0;
}