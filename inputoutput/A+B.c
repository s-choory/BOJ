#include <stdio.h>

int main(void)
{
    int A;
    int B;
    double C;

    scanf("%d", &A);
    scanf("%d", &B);
    C = (double)A / (double)B;
    printf("%.9f", C);
    return (0);
}
