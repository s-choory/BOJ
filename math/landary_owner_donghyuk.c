#include <stdio.h>

int main(void)
{
    int T, q, d, n, p;
    scanf("%d", &T);

    int C[T];
    for(int i=0; i<T; i++)
        scanf("%d", &C[i]);
    
    for(int i=0; i<T; i++)
    {
        q=0, d=0, n=0, p=0; 
        while(C[i] > 0)
        {
            if(C[i] - 25 >= 0)
            {
                q++;
                C[i] -= 25;
            }
            else if(C[i] - 10 >= 0)
            {
                d++;
                C[i] -= 10;
            }
            else if(C[i] - 5 >= 0)
            {
                n++;
                C[i] -= 5;
            }
            else if(C[i] - 1 >= 0)
            { 
                p++;
                C[i] -= 1;
            }
        }
        printf("%d %d %d %d\n", q, d, n, p);
    }
    return 0;
}