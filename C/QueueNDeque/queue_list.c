#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct Queue{
    struct Node *front;
    struct Node *rear;
    int count;
}Queue;

Queue *queue = NULL;

void InitQueue()
{
    queue->front = NULL; 
    queue->rear = NULL;
    queue->count = 0;
}


int IsEmpty()
{   
    if(queue -> count == 0)
        return 1;
    else 
        return 0;
}

void enqueue(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    if(IsEmpty())
        queue->front = newNode;
    else{
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->count++;
}

int dequeue()
{
    if(IsEmpty())
        return -1;
    Node *ptr = queue -> front;
    int data = ptr -> data;
    queue -> front = ptr -> next;
    free(ptr);
    queue->count--;

    return data;
}

int main(void)
{
    int n, c;
    char arr[7];
    scanf("%d", &n);
    queue = (Queue*)malloc(sizeof(Queue));
    InitQueue();

    for(int i=0; i<n; i++)
    {
        scanf("%s", arr);
        if(strcmp(arr, "pop") == 0)
            printf("%d\n", dequeue());
        else if(strcmp(arr, "size") == 0)
            printf("%d\n", queue->count);
        else if(strcmp(arr, "front") == 0)
        {
            if(queue->front == NULL)
                printf("-1\n");
            else
                printf("%d\n", queue->front->data);
        }
        else if(strcmp(arr, "back") == 0)
        {
            if(queue->rear == NULL)
                printf("-1\n");
            else
                printf("%d\n", queue->rear->data);
        }
        else if(strcmp(arr, "empty") == 0)
            printf("%d\n", IsEmpty());
        else if(strcmp(arr, "push") == 0)
        {
            scanf("%d", &c);
            enqueue(c);
        }
    }
}