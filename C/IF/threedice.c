#include <stdio.h>

int main(void)
{
    int x, y, z, money;

    scanf("%d %d %d", &x, &y, &z);
    
    if (x == y && y == z)
    money = 10000 + (x * 1000);
    else if (x == y || y == z || z == x)
    {
        if (x == y || z == x)
        money = 1000 + (x * 100);
        else
        money = 1000 + (y * 100);
    }
    else
    {
        if (x >= y && x >= z)
        money = x * 100;
        else if (y >= z && y >= x)
        money = y * 100;
        else if (z >= x && z >= y)
        money = z * 100;
    }
    printf("%d", money);
    return 0;
}