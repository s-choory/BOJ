#include <stdio.h>
#include <stdlib.h>

struct DLinkedList{
    struct DLinkedList *llink; //이전 노드(왼쪽) 을 가리킬 구조체 포인터
    int data;   //데이터를 담을 데이터 변수
    struct DLinkedList *rlink;  //다음 노드(오른쪽) 을 가리킬 구조체 포인터
};

struct DLinkedList *creatNode(int data) //구조체 포인터를 반환. 인자로 넣을 데이터를 받는다.
{
    struct DLinkedList *newNode;    //새로운 구조체 포인터 생성
    newNode = (struct DLinkedList*)malloc(sizeof(struct DLinkedList));  //구조체 포인터에 동적할당
    if(newNode == NULL){
        printf("동적 할당 에러\n");
        return 0;
    }

    newNode -> llink = NULL;    //이전 노드를 가리키는 포인터에 NULL삽입
    newNode -> data = data;     //데이터 변수에 데이터 삽입
    newNode -> rlink = NULL;    //다음 노드를 가리키는 포인터에 NULL삽입

    return newNode;     //구조체 포인터를 반환
}

void insertNode(struct DLinkedList **phead, struct DLinkedList *newNode) //이중 포인터는 함수 내에서 값 변화가 있을 때 함수가 끝나도 변경시킨 값이 초기화되지 않도록 하기위해 사용한다.
{
    if(*phead == NULL){ //헤드포인터가 가리키는게 아무것도 없다면(노드가 없다면)
        *phead = newNode;   //헤드포인터에 새로운 노드의 주소를 넣는다.
    }
    else{
        newNode -> rlink = *phead;; //새로운 노드의 다음노드칸(rlink)에 헤드포인터가 가리키는 노드의 주소를 넣는다.
        (*phead) -> llink = newNode; //헤드포인터가 가르키는 노드의 이전노드칸(llink)에 새로운 노드의 주소를 넣는다.
        *phead = newNode;   //헤드포인터에 새로운 주소를 넣는다.
    }
}

void removeNode(struct DLinkedList **phead) //인자로 헤드포인터를 받는다.
{
    struct DLinkedList *p = *phead; //삭제할 노드의 주소를 담을 구조체포인터 변수

    if (*phead == NULL) //노드가 아무것도 없다면
    {
        printf("연결리스트가 비어있습니다.\n");
        return;
    }
    else{
        *phead = (*phead) -> rlink; //헤드포인터에 헤드포인터가 가르키는 노드의 다음노드의 주소를 넣는다.
        free(p);   //삭제할 노드 동적 할당 해제
    }
}

void display(struct DLinkedList *list)
{
    while (list != NULL){
        printf("%d ", list->data);
        list = list->rlink;
    }
    printf("\n");
}

int main(void){
    struct DLinkedList *list = NULL;

    insertNode(&list, creatNode(10));
    insertNode(&list, creatNode(20));
    insertNode(&list, creatNode(30));
    insertNode(&list, creatNode(40));
    display(list);

    removeNode(&list);
    removeNode(&list);
    display(list);
    return 0;
}