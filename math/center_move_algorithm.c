#include <stdio.h>

int main(void)
{
    int n, a=2, sum = 4, b = 1;

    scanf("%d", &n);

    for(int i=1; i<=n; i++)
    {
        sum = sum + 2*(a*(a-1)) + b*b;
        a= a*2 -1;
        b = b*2;
    }
    printf("%d", sum);
    return 0;
}