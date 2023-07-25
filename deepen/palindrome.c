#include <stdio.h>
#include <string.h>

int main(void)
{
    char arr[100];
    scanf("%s", arr);
    int len = strlen(arr);

    int i = 0;
    while(i < len / 2)
    {
        if (arr[i] != arr[len - i - 1])
        {
            printf("0");
            return 0;
        }
        i++;
    }
    printf("1");
    return 0;
}