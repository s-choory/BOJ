#include <stdio.h>
#include <math.h>

int is_prime[1000001];  //n이 합성수면 0, 소수면 1
int primes[1000001];    //index 0부터 소수 대입

void sieve(int n)
{
    int cnt = 0;
    is_prime[0] = is_prime[1] = 0;
    for(int i=2; i<=n; i++)
        is_prime[i] = 1;
    for(int i=2; i<=n; i++)
    {
        if(is_prime[i]){
            primes[cnt++] = i;
            for(int j=i*2; j<=n; j += i)
                is_prime[j] = 0;
        }
    }
}

int main(void)
{
    int T, n, cnt, j, k;
    scanf("%d", &T);
    sieve(1000000);
    for(int i=0; i<T; i++)
    {
        cnt = 0;
        scanf("%d", &n);
        j = 0;
        while(primes[j] <= n/2)
        {
            if(is_prime[n - primes[j]])
                cnt++;
            j++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}