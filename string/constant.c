#include <stdio.h>

int swap(int num)
{
   int result = 0;
   while(num > 0)
   {
       result = result * 10 + (num % 10);
       num = num / 10;
   }
   return result;
}

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);

    a = swap(a);
    b = swap(b);

    if (a > b)
        printf("%d\n", a);
    else
        printf("%d\n", b);
    return 0;
}