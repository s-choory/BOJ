#include <stdio.h>

int main(void)
{
    int n, a = 1;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        a *= 2;
    printf("%d", a);
}