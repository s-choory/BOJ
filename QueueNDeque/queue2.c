#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct NODE {
    int nData;
    struct NODE *next;
}NODE;

NODE g_head = { 0 };
int Cnt = 0;

int IsEmpty()
{
    if(g_head.next == NULL)
        return 1;
    
    return 0;
}

int InsertAtHead(int pData)
{
    NODE *pNode = (NODE*)malloc(sizeof(NODE));
    pNode->nData = pData;

    if(IsEmpty())
        g_head.next = pNode;
    else
    {
        pNode -> next = g_head.next;
        g_head.next = pNode;
    }
    return 1;
}

int InsertAtTail(int pData)
{
    NODE* pTmp = &g_head;
    while(pTmp->next != 0)
        pTmp = pTmp->next;

    NODE *pNode = (NODE*)malloc(sizeof(NODE));
    pNode->nData = pData;

    pTmp -> next = pNode;
    Cnt++;
}

void ReleaseList(void)
{
    NODE *pTmp = g_head.next;
    while(pTmp != NULL){
        NODE* pDelete = pTmp;
        pTmp = pTmp->next;

        printf("Delete: [%p] [%d]\n", pDelete, pDelete->nData);
        free(pDelete);
    }
    g_head.next = NULL;
}

NODE* FindData(int pData)
{
    NODE *pTmp = g_head.next;
    NODE *pPrev = &g_head;
    while(pTmp != NULL)
    {
        if(pTmp->nData == pData)
            return pPrev;
        pTmp = pTmp -> next;
        pPrev = pPrev->next;
    }
    return 0;
}

int DeleteData(int pData)
{
    NODE *pPrev = FindData(pData);
    if(pPrev != 0)
    {
        NODE* pDelete = pPrev -> next;
        pPrev->next = pDelete->next;

        printf("DeleteData(): %d\n", pDelete->nData);
        free(pDelete);
        return 1; 
    }
    return 0;
}
//연결리스트 전체 데이터 출력
void PrintList()
{
    NODE *pHead = g_head.next;
    while(pHead != NULL)
    {
        printf("[%p] %d, next[%p]\n", pHead, pHead->nData, pHead->next);
        pHead = pHead->next;
    }
    putchar('\n');
}
// Stack -> push, pop
void PushData(int pData)
{
    InsertAtHead(pData);
}

int PopData(NODE* pPopNode) {

    NODE* sp = g_head.next;
    if(IsEmpty())
        return -1;
    int value = sp->nData;
    Cnt--;
    g_head.next = sp->next;
    free(sp);
    return value;
}
// Queue -> Enqueue, Dequeue
int Enqueue(int pData)
{
    return InsertAtTail(pData);
}

int Dequeue(NODE* pGetNode)
{
    return PopData(pGetNode);
}

int front()
{
    NODE* node = g_head.next;
    if(IsEmpty())
        return -1;
    int value = node->nData;
    return value;
}

int back()
{
    NODE* node = g_head.next;
    if(IsEmpty())
        return -1;
    while(node->next != 0)
        node = node->next;
    int value = node->nData;
    return value;
}

int main(void)
{
    int n, c;
    char arr[6];
    NODE node = { 0 };
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
    {
        scanf("%s", arr);
        if(strcmp(arr, "pop") == 0)
            printf("%d\n", Dequeue(&node));
        else if(strcmp(arr, "size") == 0)
            printf("%d\n", Cnt);
        else if(strcmp(arr, "front") == 0)
            printf("%d\n", front());
        else if(strcmp(arr, "back") == 0)
            printf("%d\n", back());
        else if(strcmp(arr, "empty") == 0)
            printf("%d\n", IsEmpty());
        else if(strcmp(arr, "push") == 0)
        {
            scanf("%d", &c);
            Enqueue(c);
        }
    }
}