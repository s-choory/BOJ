#include <stdio.h>

int main(void)
{
    char arr[100];
    int n = 0;

    while(1)
    {
        scanf("%c", &arr[n]);
        if(arr[n] >= 'a' && arr[n] <= 'z' || arr[n] >= 'A' && arr[n] <= 'Z')
            n++;
        else
            break;
    }
    printf("%d", n); 
    return 0;
}