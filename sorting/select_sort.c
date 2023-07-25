#include <stdio.h>

int main(void)
{
    int tmp, n, arr[1000] = { 0 };

    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]>arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    for(int i=0; i<n; i++)
        printf("%d\n", arr[i]);
    return 0;
}