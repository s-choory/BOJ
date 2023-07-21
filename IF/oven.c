#include <stdio.h>

int main(void)
{
    int hour, minute, minute2, alltime;

    scanf("%d %d %d", &hour, &minute, &minute2);

    alltime = (hour * 60) + minute + minute2;
    hour = alltime / 60;
    minute = alltime % 60;
    if (23 < hour)
    hour = hour - 24;
    printf("%d %d", hour, minute);

    return 0;
}