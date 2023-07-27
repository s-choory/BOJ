#include <stdio.h>
#include <string.h>

int main(void)
{
    char S[101] = {0 };
    int alpha[26];
    int index = 0;

    memset(alpha, -1, sizeof(alpha));
    scanf("%s", S);

    for(int i = 0; i < 100; i++)
    {
        index = S[i] - 'a';
        if(alpha[index] == -1)
            alpha[index] = i;
    }
    for(int i = 0; i < 26; i++)
    {
        printf("%d ", alpha[i]);
    }    
    return 0;
}