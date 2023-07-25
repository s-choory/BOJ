#include <stdio.h>

int main(void)
{
    int n, a, b, c, cnt = 0, arr[1001] = { 0 };

    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        if(a >= b)
            c = b;
        else
            c = a;
        while(c > 0)
        {
            if(a % c == 0 && b % c == 0)
                break;
            c--;
        }
        arr[i] = (a * b) / c;
        cnt++;
    }
    for(int i=0; i<cnt; i++)
        printf("%d\n", arr[i]);
    return 0;
}