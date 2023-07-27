#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10007

struct node{
    char key[501];
    struct node* next;
};

struct bucket{
    struct node* head;
};

struct bucket hashTable[SIZE];

int hashFunction(char* key){
    int sum = 0;
    for(int i=0; i<strlen(key); i++)
        sum += key[i];
    return sum % SIZE;
}

struct node* createNode(char *key)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->key, key);
    newNode->next = NULL;

    return newNode;
}

void insert(char* key)
{   
    int hashIndex = hashFunction(key);

    struct node* newNode = createNode(key);

    if(hashTable[hashIndex].head == NULL)
        hashTable[hashIndex].head = newNode;
    else
    {
        newNode -> next = hashTable[hashIndex].head;
        hashTable[hashIndex].head = newNode;
    }
    return ;
}

int search(char* key)
{
    int hashIndex = hashFunction(key);
    struct node *node = hashTable[hashIndex].head;

    while(node != NULL)
    {
        if(strcmp(node->key, key) == 0)
            return 1;
        node = node->next;
    }
    return 0;
}

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);

    char input[501];
    for(int i=0; i<N; i++)
    {
        scanf("%s", input);
        insert(input);
    }

    int count = 0;
    for(int i=0; i<M; i++)
    {
        scanf("%s", input);
        if(search(input))
            count++;
    }
    printf("%d", count);
    return 0;
}