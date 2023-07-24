#include <stdio.h>

int main(void)
{
    int n, num;

    num = 0;
    scanf("%d", &n);
    while (n > 0)
    {
        num += n;
        n--;
    }
    printf("%d", num);
    return 0;
}