#include <stdio.h>

int main(void)
{
    int a, i, origin;

    scanf("%d", &a);
    origin = a;
    i = 1;
    while (i)
    {
        a = ((a % 10) * 10) + ((a / 10 + a % 10) % 10);
        i++;
        if(a == origin)
        break;
    }
    i--;
    printf("%d", i);
    return 0;
}