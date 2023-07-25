#include <stdio.h>

int main(void)
{
    long long n, sum = 0;

    scanf("%lld", &n);
    
    if(n < 3)
    {
        printf("0\n3");
        return 0;
    }
    sum = n * (n - 1) * (n - 2) / 6;
    printf("%lld\n", sum);
    printf("3");
    return 0;
}