#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node* next;
};

struct node *top = NULL;

void push(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL){
        printf("stack is full!");
        exit(1);
    }
    newNode -> data = data;
    newNode -> next = top;
    top = newNode;
}

int pop(){
    struct node* delete;
    int value;

    if(top == NULL){
        printf("stack is empty!");
        exit(1);
    }

    value = top -> data;
    delete = top;
    top = top -> next;
    free(delete);

    return value;
}

void display(){
    struct node* node;
    struct node* count = top;

    node = count;

    while(node != NULL)
    {
        if(node->next == NULL)
            printf("%d\n", node->data);
        else
            printf("%d -->", node->data);
        node = count -> next;
        count = count -> next;
    }
}

int main(void)
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();

    pop();
    pop();
    
    display();
    return 0;
    
}
