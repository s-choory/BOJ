#include <stdio.h>

int main(void)
{
    int i, j, tmp;
    int arr[30];
    
    i = 0;
    while(i < 28)
    {
        scanf("%d", &arr[i]);
        i++;
    }
    i = 0;
    while(i < 28)
    {
        j = 1;
        while(j < 28)
        {
            if (arr[j] < arr[j - 1])
            {
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
            j++;
        }
        i++; 
    }
    i = 0;
    if(arr[0] != 1)
        printf("1\n");

    while(i < 28)
    {
        if(arr[i] + 1 != arr[i + 1] && arr[i] != 30)
        {
            printf("%d\n", arr[i] + 1);
        }
        i++;
    }
    return 0;
}