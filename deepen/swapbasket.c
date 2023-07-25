#include <stdio.h>

int main(void)
{
    int N, M, tmp = 0;
    int a, b, c; 

    scanf("%d %d", &N, &M);
    int arr[100], arr2[100];
    for(int i = 1; i <= N; i++)
        arr[i] = i;
    for(int j = 0; j < M; j++)
    {
        scanf("%d %d %d", &a, &b, &c);
        for(int i = 1; i <= N; i++)
            arr2[i] = arr[i];
        for(int k = a ; k <= b ; k++)
        {
            arr[k] = arr2[c];
            c++;
            if(c > b)
                c = a;
        }
    }
    for(int i = 1; i <= N; i++)
        printf("%d ", arr[i]);
    return 0;
}