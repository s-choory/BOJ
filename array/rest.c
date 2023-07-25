#include <stdio.h>

int main(void)
{
    int i, j, k;
    int arr[10] = {0}, arr2[10] = {0};
    
    i = 0;
    k = 0;
    while (i < 10)
    {
        scanf("%d", &arr[i]);
        j = 0;
        arr2[k] = arr[i] % 42;
        while (j < k)
        {  
            if(arr2[k] == arr2[j])
            {
                k--;
                break;
            }
            j++;
        }
        i++;
        k++;
    }
    printf("%d", k);
    return 0;
}