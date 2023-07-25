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

int main(void)
{
    int n;
    
    scanf("%d", &n);
    NODE *node = { 0 };
    for(int i=1; i<=n; i++)
    {
        Enqueue(i);
    }
    
    while(Cnt > 1)
    {
        Dequeue(node);
        Enqueue(front());
        Dequeue(node);
    }
    printf("%d", front());
    return 0;
}