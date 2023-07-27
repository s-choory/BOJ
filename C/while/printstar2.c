#include <stdio.h>

int main(void)
{
    int i, j, k, n;

    i = 0;
    scanf("%d", &n);
    while (i < n)
    {
        j = n - i - 1;
        k = 0;
        while(k < j)
        {
            printf(" ");
            k++;
        }
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