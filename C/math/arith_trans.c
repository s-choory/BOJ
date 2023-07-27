#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char N[100];
    int b, digit, decimal = 0;

    scanf("%s %d", N, &b);

    int len = strlen(N);
    for (int i = 0; i < len; i++) 
    {
        if (N[len - i - 1] >= '0' && N[len - i - 1] <= '9')  // if digit is a number
            digit = N[len - i - 1] - '0';
        else if(N[len - i - 1] >= 'A' && N[len - i - 1] <= 'Z')
            digit = N[len - i - 1] - 'A' + 10;
        decimal += digit * pow(b, i);
    }

    printf("%d\n", decimal);

    return 0;
}