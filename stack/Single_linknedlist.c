#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct NODE {
    char szData[64];
    int nData;
    struct NODE *next;

}NODE;

NODE g_head = { 0 };

int IsEmpty()
{
    if(g_head.next == NULL)
        return 1;
    
    return 0;
}

int InsertAtHead(char* pszData)
{
    NODE *pNode = (NODE*)malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));
    strcpy(pNode->szData, pszData);

    if(IsEmpty())
        g_head.next = pNode;
    else
    {
        pNode -> next = g_head.next;
        g_head.next = pNode;
    }
    return 1;
}

int InsertAtTail(char* pszData)
{
    NODE* pTmp = &g_head;
    while(pTmp->next != 0)
        pTmp = pTmp->next;

    NODE *pNode = (NODE*)malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));
    strcpy(pNode->szData, pszData);

    pTmp -> next = pNode;
}

void ReleaseList(void)
{
    NODE *pTmp = g_head.next;
    while(pTmp != NULL){
        NODE* pDelete = pTmp;
        pTmp = pTmp->next;

        printf("Delete: [%p] [%s]\n", pDelete, pDelete->szData);
        free(pDelete);
    }
    g_head.next = NULL;
}

NODE* FindData(char *pszData)
{
    NODE *pTmp = g_head.next;
    NODE *pPrev = &g_head;
    while(pTmp != NULL)
    {
        if(strcmp(pTmp->szData, pszData) == 0);
            return pPrev;
        pTmp = pTmp -> next;
        pPrev = pPrev->next;
    }
    return 0;
}

int DeleteData(char *pszData)
{
    NODE *pPrev = FindData(pszData);
    if(pPrev != 0)
    {
        NODE* pDelete = pPrev -> next;
        pPrev->next = pDelete->next;

        printf("DeleteData(): %s\n", pDelete ->szData);
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
        printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
        pHead = pHead->next;
    }
    putchar('\n');
}
// Stack -> push, pop
void PushData(char* pszData)
{
    InsertAtHead(pszData);
}

int PopData(NODE* pPopNode) {

    NODE* sp = g_head.next;
    if(IsEmpty())
        return 0;
    
    memcpy(pPopNode, sp, sizeof(NODE));

    g_head.next = sp->next;
    free(sp);
    return 1;
}
// Queue -> Enqueue, Dequeue
int Enqueue(char* pszData)
{
    return InsertAtTail(pszData);
}

int Dequeue(NODE* pGetNode)
{
    return PopData(pGetNode);
}

int main(void)
{
    Enqueue("TEST01");
    Enqueue("TEST02");
    Enqueue("TEST03");

    PrintList();
    
    NODE node = { 0 };
    if(Dequeue(&node) == 0)
        puts("empty");

    ReleaseList();
    return 0;
}