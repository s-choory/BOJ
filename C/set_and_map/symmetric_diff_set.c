#include <stdio.h>
#include <stdlib.h>

struct bucket* hashTable = NULL;
int SIZE = 100007;

struct node{
    int key;
    int value;
    struct node* next;
};

struct bucket{
    struct node* head;
    int count;
};

struct node* creatNode(int key){
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->key = key;

    newNode->next = NULL;
    return newNode;
};

int hashFunction(int key){
    return key % SIZE;
}

void insert(int key)
{
    struct node* node = creatNode(key);
    int hashIndex = hashFunction(key);

    if(hashTable[hashIndex].count == 0){
        hashTable[hashIndex].head = node;
        hashTable[hashIndex].count++;
    }
    else{
        node -> next = hashTable[hashIndex].head;
        hashTable[hashIndex].head = node;
        hashTable[hashIndex].count++;
    }
    return ;
}

void key_remove(int key){
    int hashIndex = hashFunction(key);
    int flag = 0;

    struct node *node;
    struct node *trace;

    node = hashTable[hashIndex].head;
    
    while(node != NULL){
        if(node -> key == key)
        {
            if(node == hashTable[hashIndex].head)
                hashTable[hashIndex].head = node -> next;
            else
                trace -> next = node -> next;
            hashTable[hashIndex].count --;
            free(node);
            flag = 1;
        }
        trace = node;
        node = node -> next;
    }
}

int search(int key){
    int hashIndex = hashFunction(key);
    struct node *node;
    int flag = 0;

    node = hashTable[hashIndex].head;

    while(node != NULL)
    {
        if(node -> key == key){
            flag = 1;
        }
        node = node -> next;
    }
    if(flag == 1)
        return 1;
    else
        return 0;
}

int main(void)
{
    hashTable = (struct bucket*)malloc(SIZE * sizeof(struct bucket));

    int n, m, input, cnt=0;

    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &input);
        insert(input);
    }
    for(int i=0; i<m; i++)
    {
        scanf("%d", &input);
        if(search(input))
            cnt++;
    }
    printf("%d", (n-cnt)+(m-cnt));
    return 0;
}