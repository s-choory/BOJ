#include <stdio.h>

int main(void)
{
    int money, n, product, num, commoney;

    scanf("%d %d", &money, &n);
    commoney = 0;
    while(n > 0)
    {
        scanf("%d %d", &product, &num);
        commoney = commoney + (product * num);
        n--;
    }
    if (money == commoney)
    printf("Yes");
    else
    printf("No");
    return 0;
}