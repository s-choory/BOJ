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