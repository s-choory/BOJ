#include <stdio.h>
#define MAX_STACK_SIZE 100001
#define TRUE 1
#define FALSE 0

int stack[MAX_STACK_SIZE];
int top_rct = 0;

int IsEmpty(){
    if(top_rct <= 0)
        return TRUE;
    else
        return FALSE;
}

int IsFull(){
    if(top_rct >= MAX_STACK_SIZE)
        return TRUE;
    else
        return FALSE;
}

void push(int value){
    if(IsFull() == FALSE)
        stack[++top_rct] = value;
}

void pop(){
    if(IsEmpty() == TRUE)
        return ;
    else
    {
        stack[top_rct] = 0;
        top_rct--;
    }
}

int main(void)
{
    int n, c, sum = 0;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &c);
        if(c == 0)
            pop();
        else
            push(c);
    }
    for(int i=1; i<=top_rct; i++)
    {
        sum += stack[i];
    }
    printf("%d", sum);
    return 0;
}
