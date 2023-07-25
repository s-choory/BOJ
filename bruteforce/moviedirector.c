#include <stdio.h>

int main(void)
{
    int n, flag, arr[10000];

    arr[1] = 666;
    for(int i = 2; i <= 10000; i++)
    {
        flag = 1;
        for(int j = arr[i - 1] + 1; flag > 0; j++)
        {
            arr[i] = j;
            while(arr[i] > 0)
            {
                if(arr[i] % 10 == 6 && (arr[i] / 10) % 10 == 6 && (arr[i] / 100) % 10 == 6)
                    {
                        flag = 0;
                        arr[i] = j;
                        break;
                    }
                arr[i] /= 10;
            }
        }
    }
    scanf("%d", &n);
    printf("%d", arr[n]);
    return 0;
} 