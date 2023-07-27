#include <stdio.h>
#include <string.h>

int main(void)
{
    char arr[1000001] = { 0 };
    int count[26] = { 0 };
    int alpha, max = 0;

    scanf("%s", arr);
    int len = strlen(arr);
    for(int i=0; i < len; i++)
    {
        if(arr[i] >= 'a' && arr[i] <= 'z')
            arr[i] -= 32;
    }
    for(int i=0; i < len; i++)
    {
        count[(int)arr[i]]++;
    }
    for(int i=65; i < 91; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
            alpha = i;
        }
    }
    for(int i = 65; i < 91; i++)
    {
        if (alpha != i && count[i] == max)
        {
            printf("?");
            return 0;
        }
    }
    printf("%c", (char)alpha);
    return 0;
}