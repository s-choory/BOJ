#include <stdio.h>
#include <string.h>

int main(void)
{
    char arr[1000] = { 0 };
    char first, last;
    int n, m, i;
    scanf("%d", &n);
    if (n < 1 || n > 10)
        return 0;
    i = 0;
    m = 0;
    while(i < n)
    {
        scanf("%s", arr);
        m = strlen(arr);
        first = arr[0];
        last = arr[m - 1];
        printf("%c%c\n", first, last);
        i++;
    }
    return 0;
}