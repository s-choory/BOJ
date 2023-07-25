#include <stdio.h>

int main() {
    char a[100];
    int N, b, cnt = 0;

    scanf("%d %d", &N, &b);

    for (int i = 0; N > 0; i++) 
    {
        if((N % b) >= 10 && (N % b) <= 35)
            a[i] = (N % b) + 'A' - 10;
        else if ((N % b) >= 0 && (N % b) <= 9)
            a[i] = (N % b) + '0';
        N /= b;
        cnt++;
    }
    
    for(int i = cnt-1; i >= 0; i--)
        printf("%c", a[i]);        
    return 0;
}