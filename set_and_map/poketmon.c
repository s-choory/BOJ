#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct node{
    char key[21];
    int value;
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

struct node* createNode(char *key, int value)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

void insert(char* key, int value)
{   
    int hashIndex = hashFunction(key);

    struct node* newNode = createNode(key, value);

    if(hashTable[hashIndex].head == NULL)
        hashTable[hashIndex].head = newNode;
    else
    {
        newNode -> next = hashTable[hashIndex].head;
        hashTable[hashIndex].head = newNode;
    }
    return ;
}

void display_value(char* key){
    struct node *node;
    char result[21];

    for(int i=0; i< SIZE; i++){
        node = hashTable[i].head;

        while(node != NULL){
            strcpy(result, node -> key);
            if(strcmp(result, key) == 0)
                printf("%d\n",node->value);
            node = node -> next;
        }
    }
    return ;
}

void display_key(char* value){
    struct node *node;

    int sum = 0;
    for(int i=0; value[i]; i++)
    {
        sum += value[i] - '0';
        sum *= 10;
    }
    sum = sum / 10;
    for(int i=0; i< SIZE; i++){
        node = hashTable[i].head;

        while(node != NULL){
            if(node->value == sum)
                printf("%s\n", node->key);
            node = node -> next;
        }
    }
    return ;
}

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);

    char input[21];
    for(int i=1; i<=N; i++)
    {
        scanf("%s", input);
        insert(input, i);
    }
    int count = 0;
    for(int i=0; i<M; i++)
    {
        scanf("%s", input);
        if(!(input[0] >= '0' && input[0] <= '9'))
            display_value(input);
        else
            display_key(input); 
    }
    return 0;
}