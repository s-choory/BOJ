#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 0 ; i < n - 1 ; i++)
    {
        for(int j = n - 1; j > i; j--)
            printf(" ");
        for(int k = 0; k < 2*i+1 ; k++)
            printf("*");
        printf("\n");
    }
    for (int i = n - 1; i >= 0 ; i--)
    {
        for(int j = n - 1; j > i; j--)
            printf(" ");
        for(int k = 0; k < 2*i+1 ; k++)
            printf("*");
        printf("\n");
    }
}