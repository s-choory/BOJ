#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100007

struct node{
    char key[1001];
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
    char arr[1001], result[SIZE];
    unsigned long long cnt=0;

    scanf("%s", arr);
    
    for(int i = 0; i < strlen(arr); i++)
    {
        for(int j=0; j+i < strlen(arr); j++)
        {
            strncpy(result, arr+j, i+1);
            if(search(result) == 0)
            {
                insert(result);
                cnt++;
            }
        }
    }
    printf("%lld", cnt);
    return 0;
}