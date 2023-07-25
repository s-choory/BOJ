#include <stdio.h>

int main(void)
{
    int N, a, b, c, d, e, f, g, sum, z= 1000000;

    scanf("%d", &N);
    
    for(int i=N; i>=N-100 && i > 0; i--)
    {
        sum = 0;
        a = i%10;
        b = (i%100 - i%10) / 10;
        c = (i%1000 - i%100) / 100;
        d = (i%10000 - i%1000) / 1000;
        e = (i%100000 - i%10000) / 10000;
        f = (i%1000000 - i%100000) / 100000;
        g = (i%10000000 - i%1000000) / 1000000;
        sum = a+b+c+d+e+f+g;
        if(N == i+sum)
        {
            if(i < z)
                z = i;
        }
    }
    if(N <= 1000000 && z == 1000000)
        z=0;
    printf("%d", z);
}