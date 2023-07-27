#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 101
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
    char c[101];
    while(1)
    {   
        scanf("%[^\n]", c);
        getchar();
        if(c[0] == '.' && strlen(c) == 1)
            break;
        for(int j=0; j<100; j++)
        {
            if(c[j] == '.')
                break;
            else if(c[j] == '(')
                push(1);
            else if(c[j] == '[')
                push(2);
            else if(c[j] == ')')
            {
                if(stack[top] == 1)
                    pop();
                else
                    flag = 1;
            }
            else if(c[j] == ']')
            {
                if(stack[top] == 2)
                    pop();
                else
                    flag = 1;
            }
        }
        if(top == 0 && flag == 0)
            printf("yes\n");
        else
            printf("no\n");
        while(top != 0)
            pop();
        flag = 0;
    }
    return 0;
}
