#include <stdio.h>

int main(void)
{
    int T, n, m;
    unsigned long long answer;

    scanf("%d", &T);
    
    for(int i=0; i<T; i++)
    {   
        answer = 1;
        scanf("%d %d", &n, &m);
        if(n > (m / 2))
            n = m - n;
        for(int i=m; i>m-n; i--)
        {
            answer *= i;
        }
        for(int j=n; j>0; j--)
        {
            answer /= j;
        }
        printf("%lld\n", answer);
    }
    return 0;
}