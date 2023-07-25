#include <stdio.h>
#include <string.h>
#define MAX_LEN 1000001

int main(void)
{
    int cnt = 0;
    char arr[MAX_LEN];
    
    fgets(arr, sizeof(arr), stdin);

    int len = strlen(arr);

    for(int i=0; i < len - 1  ; i++)
    {
        if(arr[i] != ' ' && (i == 0 || arr[i-1] == ' '))
            cnt++; 
    }
    printf("%d", cnt);
    return 0;
}