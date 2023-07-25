#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100007

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

void key_remove(char* key){
    int hashIndex = hashFunction(key);

    struct node* node;
    struct node* trace; //single linked list기 때문에 trace 추가. 

    node = hashTable[hashIndex].head;

    while(node != NULL){
        if(strcmp(node -> key, key) == 0){
            if(node == hashTable[hashIndex].head)
                hashTable[hashIndex].head = node->next; //제거 전 head를 먼저 옮겨줘야 head가 NULL값이 되는 오류가 사라진다.
            else
                trace -> next = node -> next;
            free(node);
        }
        trace = node;       // next로 바꾸기 전의 node를 trace에 저장한다.
        node = node ->next;  //노드를 계속해서 next로 옮겨주며 해당 key를 찾게한다.
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
    int N, cnt = 0, real_cnt=0;
    scanf("%d", &N);

    char input[21];
    char result[100007][21];

    for(int i=0; i<N; i++)
    {
        scanf("%s", input);
        
        if(strcmp(input, "ENTER") == 0)
        {
            for(int j=0; j<cnt; j++)
                key_remove(result[j]);
            cnt = 0;
        }
        else
        {   
            if(search(input) == 0)
            {
                insert(input);
                strcpy(result[cnt], input);
                cnt++;
                real_cnt++;
            }
        }
    }
    printf("%d", real_cnt);
    return 0;
}