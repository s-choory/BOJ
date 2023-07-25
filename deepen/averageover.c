#include <stdio.h>

int main(void)
{
    int n, m;
    int arr[1000000] = { 0 };
    scanf("%d", &n);

    for(int i=0; i < n ; i++)
    {
        double sum = 0, over = 0, cnt = 0;
        scanf("%d", &m);
        for(int j=0; j < m; j++)
        {
            scanf("%d", &arr[j]);
            sum += arr[j];
        }
        sum = sum / m;
        for(int k=0; k < m; k++)
        {
            if(arr[k] > sum)
                cnt++;
        }
        printf("%.3lf%%\n",cnt / m * 100);
    }
    return 0;
}