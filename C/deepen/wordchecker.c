#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, len, cnt=0;
    char arr[100];
    scanf("%d", &n);

    for(int i=0; i<n ; i++)
    {
        int flag = 0;
        scanf("%s", arr);
        len = strlen(arr);
        for(int j=0; j < len; j++)
        {
            if(arr[j] != arr[j+1])
            {
                for(int k=j+2; k < len; k++)
                    {
                        if(arr[j] == arr[k])
                            flag++;
                    }
            }
        }
        if(flag == 0)
            cnt++;   
    }
    printf("%d", cnt);
    return 0;
}