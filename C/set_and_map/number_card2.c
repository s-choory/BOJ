#include <stdio.h>
#include <stdlib.h>

struct bucket *hashTable = NULL;
int SIZE = 20000003;

struct node{
    int key;
    struct node* next;
};

struct bucket{
    struct node *head;
    int count;
};

struct node* createNode(int key)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    newNode -> key = key;
    newNode -> next = NULL;
    return newNode;
};

int hashFunction(int key)
{
    if(key < 0)
        return (key + 10000002) % SIZE;
    else
        return key % SIZE;
}

void insert(int key)
{
    struct node *newNode = createNode(key);
    int hashindex = hashFunction(key);

    if(hashTable[hashindex].count == 0)
    {
        hashTable[hashindex].head = newNode;
        hashTable[hashindex].count = 1;
    }
    else
    {
        newNode->next = hashTable[hashindex].head;
        hashTable[hashindex].head = newNode;
        hashTable[hashindex].count++;
    }
}

void display(int key)
{
    int hashindex = hashFunction(key);

    printf("%d ", hashTable[hashindex].count);
}

int main(void)
{
    int n, m, input;

    hashTable = (struct bucket*)malloc(sizeof(struct bucket) * SIZE);
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &input);
        insert(input);
    }
    scanf("%d", &m);
    int arr[m];
    for(int i=0; i<m; i++)
        scanf("%d", &arr[i]);
    for(int i=0; i<m; i++)
    {
        display(arr[i]);
    }
    return 0;
}