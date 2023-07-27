#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 2007

struct node{
    char key[21];
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

int search(char* key){
    int hashIndex = hashFunction(key);
    struct node *node;
    int flag = 0;

    node = hashTable[hashIndex].head;

    while(node != NULL)
    {
        if(strcmp(node -> key, key) == 0){
            flag = 1;
        }
        node = node -> next;
    }
    if(flag == 0)
        return 0;
    return 1;
}

int main(void)
{
    int N, cnt = 1;
    scanf("%d", &N);

    char input1[21], input2[21];

    insert("ChongChong");
    for(int i=0; i<N; i++)
    {
        scanf("%s %s", input1, input2);
        if(search(input1) == 1 && search(input2) == 0)
        {
            insert(input2);
            cnt++;
        }
        else if(search(input2) == 1 && search(input1) == 0)
        {
            insert(input1);
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}