#include <stdio.h>

int main(void)
{
    int n, i, max;
    double aver;

    scanf("%d", &n);
    double arr[n];

    i = 0;
    arr[0] = 0;
    max = arr[0];
    while(i < n)
    {
        scanf("%lf", &arr[i]);
        if (max < arr[i])
            max = arr[i];
        i++;
    }
    i = 0;
    while(i < n)
    {
        aver = aver + ((arr[i] / max) * 100);
        i++;
    }
    aver /= n;
    printf("%lf", aver);
    return 0;
}