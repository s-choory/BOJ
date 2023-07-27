#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 10001
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
        printf("-1\n");
    else
    {
        printf("%d\n", stack[top_rct]);
        stack[top_rct] = 0;
        top_rct--;
    }
}

void size(){
    printf("%d\n", top_rct);
}

void empty(){
    if(IsEmpty() == TRUE)
        printf("1\n");
    else
        printf("0\n");
}

void top(){
    if(IsEmpty() == TRUE)
        printf("-1\n");
    else
        printf("%d\n", stack[top_rct]);
}

int main(void)
{
    int n, c;
    char arr[7];
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%s", arr);
        if(strcmp(arr, "pop") == 0)
            pop();
        else if(strcmp(arr, "size") == 0)
            size();
        else if(strcmp(arr, "empty") == 0)
            empty();
        else if(strcmp(arr, "top") == 0)
            top();
        else if(strcmp(arr, "push") == 0)
        {
            scanf("%d", &c);
            push(c);
        }
    }
    return 0;
}
