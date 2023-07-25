#include <stdio.h>

int main(void)
{
    long long int a, b, c;

    scanf("%lld %lld", &a, &b);
    if(a >= b)
        c = b;
    else
        c = a;
    while(c > 0)
    {
        if(a % c == 0 && b % c == 0)
            break;
        c--;
    }
    c = (a * b) / c;
    printf("%lld", c);
    return 0;
}