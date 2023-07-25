#include <stdio.h>

int main(void)
{
    int n, k, answer = 1;

    scanf("%d %d", &n, &k);

    for(int i=n; i>n-k; i--)
    {
        answer *= i;
    }
    for(int j=k; j>0; j--)
    {
        answer /= j;
    }
    printf("%d", answer);
    return 0;
}