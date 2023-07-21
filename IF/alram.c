#include <stdio.h>

int main(void)
{
    int hour, minute;

    scanf("%d %d", &hour, &minute);
    if (45 <= minute)
    printf("%d %d", hour, minute - 45);
    else if (45 > minute && 0 < hour)
    printf("%d %d", hour - 1, 15 + minute);
    else if (45 > minute && 0 == hour)
    printf("%d %d", 23 - hour, 15 + minute);
    else
    printf("0 0");
    
    return 0;
}