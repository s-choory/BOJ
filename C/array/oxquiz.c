#include <stdio.h>

int main(void)
{
    int n, i, j, cnt;
    
    scanf("%d", &n);
    char arr[n][80];

    i = 0;
    while (i < n)
    {
        scanf("%s", &arr[i][80]);
        j = 0;
        while (j < 80)
        {
            if (arr[i][j] == 'O' && arr[i][j + 1] == 'O')
                cnt++;
            else if(arr[i][j] == 'O')
                cnt++;
            j++;
            if (arr[i][j] != '0' || arr[i][j] != 'X')
                break;
        }
        i++;
    }
    printf("%d", cnt);
    return 0;
}