#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100007

struct node{
    char key[6];
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

void merge(char result[][6], int start, int mid, int end) {
    char temp[end-start+1][6];
    int i = start, j = mid+1, k = 0;

    while(i <= mid && j <= end) {
        if(strcmp(result[i], result[j]) > 0) {
            strcpy(temp[k], result[i]);
            i++;
        } else {
            strcpy(temp[k], result[j]);
            j++;
        }
        k++;
    }

    while(i <= mid) {
        strcpy(temp[k], result[i]);
        i++;
        k++;
    }

    while(j <= end) {
        strcpy(temp[k], result[j]);
        j++;
        k++;
    }

    for(i = start, k = 0; i <= end; i++, k++)
        strcpy(result[i], temp[k]);
}

void mergeSort(char result[][6], int start, int end) {
    if(start < end) {
        int mid = (start+end)/2;
        mergeSort(result, start, mid);
        mergeSort(result, mid+1, end);
        merge(result, start, mid, end);
    }
}

void display(){
    struct node *node;
    char result[SIZE][6];
    int cnt = 0;

    for(int i=0; i < SIZE; i++){
        node = hashTable[i].head;
        while(node != NULL){
            strcpy(result[cnt], node -> key);
            node = node -> next;
            cnt++;
        }
    }
    mergeSort(result, 0, cnt - 1);

    for(int i=0; i< cnt; i++)
    {
        printf("%s\n", result[i]);
    }
    return ;
}

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);

    char input[6];
    char con[6];
    for(int i=0; i<N; i++)
    {
        scanf("%s %s", input, con);
        if(strcmp(con, "enter") == 0)
            insert(input);
        else if(strcmp(con, "leave") == 0)
            key_remove(input);
    }
    display();
    return 0;
}