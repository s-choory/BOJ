#include <stdio.h>

int main(void)
{
    int i, j, n;

    i = 0;
    j = 0;
    scanf("%d", &n);
    while (i < n)
    {
        j = n - i - 1;
        while (j < n)
        {
            printf("*");
            j++;
        }
        i++;
        printf("\n");
    }
    return 0;
}