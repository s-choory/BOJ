#include <stdio.h>

int main(void)
{
    int i;

    scanf("%d", &i);
    if(90 <= i)
    printf("A");
    else if(80 <= i)
    printf("B");
    else if(70 <= i)
    printf("C");
    else if(60 <= i)
    printf("D");
    else
    printf("F");
    return (0);
}