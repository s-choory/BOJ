#include <stdio.h>

int main(void)
{
    int i, A, B;

    i = 1;
    while(i)
    {
        scanf("%d %d", &A, &B);
        if(A == 0 && B == 0)
            break;
        printf("%d\n", A+B);
    }
    return 0;
}