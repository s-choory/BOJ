#include <stdio.h>

int main(void)
{
    int n, tmp, arr[10] = { 0 }, cnt = 0;

    scanf("%d", &n);
    
    for(int i=0; n>0; i++)
    {
        arr[i] = n % 10;
        n /= 10;
        cnt++;
    }
    for(int i=0; i<cnt; i++)
    {
        for(int j=i+1; j<cnt; j++)
        {
            if(arr[i] < arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    for(int i=0; i<cnt; i++)
        printf("%d", arr[i]);
    return 0;
}