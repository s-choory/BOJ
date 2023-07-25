#include <stdio.h>
#include <stdlib.h>

struct bucket* hashTable = NULL;    //해시테이블은 bucket을 통해 접근하기 때문에 hashTable이름으로 bucket배열 주소값 선언.
int SIZE = 10;

struct node{
    int key;    //해시 함수에 사용될 키
    int value;      //key가 가지고 있는 데이터
    struct node* next;  //다음 노드를 가르키는 포인터
};

struct bucket{
    struct node* head;  //버켓 가장 앞에 있는 노드의 포인터
    int count;  //버켓에 들어있는 노드의 개수
};

struct node* creatNode(int key, int value){

    struct node* newNode;  //새로운 노드 포인터 생성

    newNode = (struct node*)malloc(sizeof(struct node)); //구조체 node 사이즈만큼의 메모리 할당받기

    newNode->key = key;
    newNode->value = value; //넘겨받은 초기 key, value로 새로 만들어질 노드 값 초기화

    newNode->next = NULL; //next포인터 NULL로 설정

    return newNode; //새롭게 만든 노드 포인터를 호출자에게 리턴
}

//key 값을 보고 해시맵에 어디서 맵핑되어야 하는지 알려주는 함수
int hashFuction(int key){ 

    return key%SIZE;    //key값이 오면 해시맵의 전체 size로 modulo 연산을 하여
                        //나온 숫자의 Bucket에 맵핑하라고 알려주는 해시함수
}
//호출될때 전달 된 key,value를 가진 노드를 해시맵 안에 넣는 함수
void insert(int key, int value)     //유저로부터 key와 value를 전달받는다.
{
    int hashIndex = hashFuction(key);  //전달된 key 값의 인덱스를 알기 위해서 해시함수를 호출한다.
                                        //그러면 해시함수에 의해 정의된 매핑방법에 따른 index를 리턴받아서 hashIndex변수에 저장한다.
    struct node *newNode = creatNode(key, value);  //전달된 key,value값을 가진 노드 생성
    
    //아무 노드(값)가 없는 경우
    if(hashTable[hashIndex].count == 0){

        hashTable[hashIndex].head = newNode;    //새로운 head 노드를 새로운 노드로 지정하고
        hashTable[hashIndex].count = 1;         //해당 Bucket의 노드 카운트를 1로 설정
    }
    //내가 넣고자 하는 인덱스에 이미 값이 있는 경우
    else{

        newNode->next = hashTable[hashIndex].head;  //새로운 노드의 next 포인터를 예전 head로 바꾼다음
        hashTable[hashIndex].head = newNode;        //Bucket의 새로운 노드로 바꾼다.
        hashTable[hashIndex].count++;               //그 다음 해당 버킷의 노드 카운트를 증가시킨다.
    }
    return ;
}
//호출될 때 전달된 key를 가진 노드를 해시맵에서 지우는 함수
void hash_remove(int key)
{
    int hashIndex = hashFuction(key);  //해시값 받아오기
    int flag = 0;
    struct node* node;  //Bucket안에 Chianing된 노드들을 하나하나 비교하면서 찾아야해서 임시 노드 포인터 생성
    struct node* trace; //중간에 있는 노드를 없애는 경우 이전 노드를 추적하여 next포인터를 연결해줘야 하기 때문에 이전노드 추적
    
    node = hashTable[hashIndex].head;   //임시 노드는 해당 버켓의 head노드를 가리키게 된다.

    if(node == NULL){    //버켓안에 아무런 노드가 없을시에, 그냥 리턴
        printf("\n no key found");
        return;
    }
    
    while(node != NULL)     //head노드부터 Null이 아닐경우 계속 루프를 돈다.
    {
        //만약 key의 값이 동일한 노드를 찾았을 경우
        if(node->key == key){  
            // next 포인터를 바꾸어 주는 부분
            if(node == hashTable[hashIndex].head){  //만약 그 노드가 Bucket의 Head일 경우
                hashTable[hashIndex].head = node->next; //Head 포인터를 다음칸으로 이동
            }
            else{
                trace->next = node->next;   //Head가 아닐 경우 이전 노드의 포인터를 현재 노드의 next가 가르키고 있는 노드로 바꾼다.
            }
            hashTable[hashIndex].count--;   //해당버켓의 정보 업데이트 후
            free(node);                     //노드 삭제
            flag = 1;
        }
        trace = node;       //현재 노드가 찾고있는 노드가 아니라면 다음 노드로 가기 전에 이전 노드를 현재 노드로 바꾸고 다음노드로 이동 
        node = node->next;
    }
    if (flag == 1)
        printf("delete [%d] key", key);
    else
        printf("\nnot key found");
    return ;
}

void search(int key){

    int hashIndex = hashFuction(key);   //해시값 받아오기
    struct node* node = hashTable[hashIndex].head;  //Bucket안에 Chianing된 노드들을 하나하나 비교하면서 찾아야해서 임시 노드 포인터인 node생성 후 그 bucket의 head노드를 point 한다.
    
    if(node == NULL){   //버켓의 head가 NULL, 해당 bucket이 비어있다면 search함수에서 종료.
        printf("\nno key found");
        return ;
    }

    while(node != NULL){    //Chaining된 버켓 안의 노드들을 보면서 만약 key값이 동일한 노드를 찾았을 경우
        //찾았다
        if(node->key == key){ //해당 노드의 key와 value를 화면에 출력하고 함수 종료.
            printf("\nkey found key = [%d] value = [%d]", node->key, node->value);
            return ;
        } 
        node = node->next;  //현재 노드가 찾고있는 노드가 아니면 다음 노드로 이동
    }
    printf("\nno key found");   //Chaining된 노드를 다 찾아봤는데도 해당 key를 가진 Node를 못찾으면 함수 종료.
    return ;
}

void display(){
    
    struct node* horse;
    int i=0;
    printf("\n-------start of display---------\n");
    for(int i=0; i<SIZE; i++){
        
        horse = hashTable[i].head;
        printf("Bucket[%d] : ", i);

        while(horse != NULL){
            printf("(key:%d, val:%d) -> ", horse->key, horse->value);
            horse = horse->next;
        }
        printf("\n");
    }
    printf("\n-------end of display---------\n");
    return ;
}

int main(void)
{
    hashTable = (struct bucket*) malloc(SIZE*sizeof(struct bucket));

    // 15 까지 값 추가
    for (int i=0; i < 16; i++){
        insert(i, 10*i);
    }
    // 몇개 더 추가
    insert(21, 210);
    insert(31, 310);
    insert(41, 410);
    hash_remove(11);
    display();
    search(11);
    search(1);
    return 0;
}