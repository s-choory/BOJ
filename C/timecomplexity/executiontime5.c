#include <stdio.h>

int main(void)
{
    int n;
    long long sum=0;

    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
                sum++;
        }
    }
    printf("%lld\n", sum);
    printf("3");
}