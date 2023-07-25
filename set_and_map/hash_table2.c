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

struct node *creatNode(int key, int value){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    newNode -> key = key;
    newNode -> value = value;

    newNode -> next = NULL;
    return newNode;
};

int hashFunction(int key){
    return key % SIZE;
}

void insert(int key, int value){
    int hashIndex = hashFunction(key);
    struct node *newNode = creatNode(key, value);

    if(hashTable[hashIndex].count == 0){
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count++;
    }
    else{
        newNode -> next = hashTable[hashIndex].head;
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count++;
    }
    return ;
}

void key_remove(int key){
    int hashIndex = hashFunction(key);
    int flag = 0;

    struct node* node;
    struct node* trace; //single linked list기 때문에 trace 추가. 

    node = hashTable[hashIndex].head;

    while(node != NULL){
        if(node -> key == key){
            if(node == hashTable[hashIndex].head)
                hashTable[hashIndex].head = node->next; //제거 전 head를 먼저 옮겨줘야 head가 NULL값이 되는 오류가 사라진다.
            else
                trace -> next = node -> next;
            hashTable[hashIndex].count--;
            free(node);
            flag = 1;
        }
        trace = node;       // next로 바꾸기 전의 node를 trace에 저장한다.
        node = node ->next;  //노드를 계속해서 next로 옮겨주며 해당 key를 찾게한다.
    }
    if(flag == 1)
        printf("\nSuccess key remove : [%d]", key);
    else
        printf("\nnot key found");
    return ;
}       

void search(int key){
    int hashindex = hashFunction(key);
    struct node* node;
    
    int flag = 0;
    node = hashTable[hashindex].head;

    while(node != NULL)
    {
        if(node -> key == key)
        {
            printf("\n key found!! key [%d] value [%d]", node->key, node->value);
            flag = 1;
        }
        node = node -> next;   
    }
    if (flag == 1)
        return ;
    else
        printf("no key found");
    return ;
}

void display(){
    struct node* horse;

    for(int i = 0; i < SIZE; i++)
    {
        horse = hashTable[i].head;
        printf("\nBucket [%d]: ", i);

        while(horse != NULL){
            printf("key: %d, value: %d -> ", horse->key, horse->value);
            horse = horse -> next;
        }
    }
    return ;
}

int main(void)
{
    hashTable = (struct bucket*)malloc(sizeof(struct bucket) * SIZE);

    insert(1, 3);
    insert(21, 6);
    insert(3, 8);
    insert(11, 4);
    key_remove(21);
    search(11);
    display();
    return 0;
}