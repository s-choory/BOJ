#include <stdio.h>

int main(void)
{
    int n, x, y;
    int max_x=-10001, max_y=-10001, min_x=10001, min_y=10001, sum;

    scanf("%d", &n);
    for(int i=0; i< n; i++)
    {
        scanf("%d %d", &x, &y);
        if(x > max_x)
            max_x = x;
        if(y > max_y)
            max_y = y;
        if(x < min_x)
            min_x = x;
        if(y < min_y)
            min_y = y;
    }
    if (n == 1)
    {
        printf("0");
        return 0;
    }
    sum = (max_x - min_x) * (max_y - min_y);
    printf("%d", sum);
    return 0;
}