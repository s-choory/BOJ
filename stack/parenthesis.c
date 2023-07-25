#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 100001
#define TRUE 1
#define FALSE 0

int stack[MAX_STACK_SIZE];
int top = 0;
int flag = 0;

int IsEmpty(){
    if(top <= 0)
        return TRUE;
    else
        return FALSE;
}

int IsFull(){
    if(top >= MAX_STACK_SIZE)
        return TRUE;
    else
        return FALSE;
}

void push(int value){
    if(IsFull() == FALSE)
        stack[++top] = value;
}

void pop(){
    if(IsEmpty() == TRUE)
    {
        flag = 1;
        return ;
    }
    else
    {
        stack[top] = 0;
        top--;
    }
}

int main(void)
{
    int n;
    char c[51];
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%s", c);
        for(int j=0; j<strlen(c); j++){
            if(c[j] != '(' && c[j] != ')')
                break;
            if(c[j] == '(')
                push(1);
            else if(c[j] == ')')
                pop();
        }
        if(top == 0 && flag == 0)
            printf("YES\n");
        else
            printf("NO\n");
        while(top != 0)
            pop();
        flag = 0;
    }
    return 0;
}
