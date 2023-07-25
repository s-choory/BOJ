#include <stdio.h>

int main(void)
{
    int arr[5] = { 0 }, sum = 0, tmp;

    for(int i=0; i<5; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i]; 
    }
    for(int i=0; i<5; i++)
    {
        for(int j=i+1; j<5; j++)
        {
            if(arr[i]>arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    sum /= 5;
    printf("%d\n%d", sum, arr[2]);
    return 0;
}