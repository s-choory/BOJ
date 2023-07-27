#include <stdio.h>

int main(void)
{
    int n;

    scanf("%d", &n);
    for(int i=n-1; i>0; i--)
    {
        n = n * i;
    }
    if(n == 0)
        n = 1;
    printf("%d", n);
}