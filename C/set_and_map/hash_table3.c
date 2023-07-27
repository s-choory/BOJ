#include <stdio.h>
#include <stdlib.h>

struct bucket* hashTable = NULL;
int SIZE = 10;

struct node{
    int key;
    int value;
    struct node* next;
};

struct bucket{
    struct node* head;
    int count;
};

struct node* creatNode(int key, int value){
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->key = key;
    newNode ->value = value;

    newNode->next = NULL;
    return newNode;
};

int hashFunction(int key){
    return key % SIZE;
}

void insert(int key, int value)
{
    struct node* node = creatNode(key, value);
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
    if(flag == 1)
        printf("\nSuccess remove key [%d]", key);
    else
        printf("\nnot key found");
}

void search(int key){
    int hashIndex = hashFunction(key);
    struct node *node;
    int flag = 0;

    node = hashTable[hashIndex].head;

    while(node != NULL)
    {
        if(node -> key == key){
            printf("\nSuccess found!! key : [%d] value : [%d]", node->key, node->value);
            flag = 1;
        }
        node = node -> next;
    }
    if(flag == 0)
        printf("\nnot key found");
    return ;
}

void display(){
    struct node *node;

    for(int i=0; i< SIZE; i++){
        node = hashTable[i].head;
        printf("\nBucket%d: ", i);

        while(node != NULL){
            printf("key [%d] value [%d] -> ", node->key, node->value);
            node = node -> next;
        }
    }
    return ;
}

int main(void)
{
    hashTable = (struct bucket*)malloc(SIZE * sizeof(struct bucket));

    for(int i=0; i<15; i++)
    {
        insert(i, i*10);
    }
    key_remove(11);
    key_remove(3);
    search(8);
    insert(1, 100);
    search(1);
    display();    
}