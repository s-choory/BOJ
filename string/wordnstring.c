#include <stdio.h>

int main(void)
{
    int n;
    char arr[1000];

    scanf("%s", arr);
    scanf("%d", &n);
    printf("%c", arr[n-1]);
}