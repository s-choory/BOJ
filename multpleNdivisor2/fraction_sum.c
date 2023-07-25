#include <stdio.h>

int main(void)
{
    int a, b, c, d, x, y, min;

    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);

    x = a * d + c * b;
    y = b * d;

    if(x >= y)
        min = y;
    else
        min = x;
    while(min > 0)
    {
        if(x % min == 0 && y % min == 0)
        {
            x = x / min;
            y = y / min;
            break;
        }
        min--;
    }
    printf("%d %d",x ,y);
    return 0;
}