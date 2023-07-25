#include <stdio.h>

int main(void)
{
    int a1, a0, c, n0;

    scanf("%d %d %d %d", &a1, &a0, &c, &n0);
    for(int n=n0; n <= 100; n++)
    {
        if((a1 * n + a0) > (c * n))
        {
            printf("0");
            return 0;
        }
    }
    printf("1");
    return 0;
}