#include <stdio.h>

int main(void)
{
    int n, i, j, k=-1;

    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i*5 + j*3 == n)
                k = i+j;
        }
    }
    printf("%d", k);
    return 0;
}