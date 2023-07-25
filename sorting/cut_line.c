#include <stdio.h>

int main(void)
{
    int N, k, arr[1000], tmp;

    scanf("%d %d", &N, &k);
    
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    for(int i=0; i<N; i++)
    {
        for(int j=i+1; j<N; j++)
        {
            if(arr[i]<arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    printf("%d", arr[k-1]);
    return 0;
}