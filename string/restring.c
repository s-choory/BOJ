#include <stdio.h>

int main(void)
{
    int n, m, len;
    char arr[20];
    scanf("%d", &n);

    for(int i=0; i < n; i++)
    {
        scanf("%d %s", &m, arr);
        for(int k=0; arr[k] != '\0'; k++)
        {
            for(int j=0; j < m; j++)
                printf("%c", arr[k]);
        }
        printf("\n");
    }
    return 0;
}