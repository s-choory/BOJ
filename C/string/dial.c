#include <stdio.h>
#include <string.h>

int main(void)
{
    char arr[16];
    
    scanf("%s", arr);
    int len = strlen(arr);
    int cnt = 0;
    for(int i =0; i < len; i++)
    {
        if (arr[i] == 'A' || arr[i] == 'B' || arr[i] == 'C')
            cnt += 3;
        else if (arr[i] == 'D' || arr[i] == 'E' || arr[i] == 'F')
            cnt += 4;
        else if (arr[i] == 'G' || arr[i] == 'H' || arr[i] == 'I')
            cnt += 5;
        else if (arr[i] == 'J' || arr[i] == 'K' || arr[i] == 'L')
            cnt += 6;
        else if (arr[i] == 'M' || arr[i] == 'N' || arr[i] == 'O')
            cnt += 7;
        else if (arr[i] == 'P' || arr[i] == 'Q' || arr[i] == 'R' || arr[i] == 'S')
            cnt += 8;
        else if (arr[i] == 'T' || arr[i] == 'U' || arr[i] == 'V')
            cnt += 9;
        else if (arr[i] == 'W' || arr[i] == 'X' || arr[i] == 'Y' || arr[i] == 'Z')
            cnt += 10;
    }
    printf("%d", cnt);
    return 0;
}