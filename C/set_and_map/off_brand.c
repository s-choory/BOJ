#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10007

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

void merge(char result[][21], int start, int mid, int end) {
    char temp[end-start+1][21];
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

void mergeSort(char result[][21], int start, int end) {
    if(start < end) {
        int mid = (start+end)/2;
        mergeSort(result, start, mid);
        mergeSort(result, mid+1, end);
        merge(result, start, mid, end);
    }
}

int main(void)
{
    int N, M, cnt = 0;
    char result[SIZE][21];
    scanf("%d %d", &N, &M);

    char nolisten[21];
    char nolook[21];
    for(int i=0; i<N; i++)
    {
        scanf("%s", nolisten);
        insert(nolisten);
    }
    for(int i=0; i<M; i++)
    {
        scanf("%s", nolook);
        if(search(nolook))
        {
            strcpy(result[cnt], nolook);
            cnt++;
        }

    }
    mergeSort(result, 0, cnt - 1);
    printf("%d\n", cnt);
    for(int i=cnt-1; i >= 0; i--)
        printf("%s\n", result[i]);
    return 0;
}