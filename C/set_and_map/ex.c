#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100007
#define MAX_KEY_LEN 6

struct bucket{
    char** keys;
    int num_keys;
};

struct bucket hashTable[SIZE];

int hashFunction(char* key){
    int sum = 0;
    for(int i=0; i<strlen(key); i++)
        sum += key[i];
    sum += strlen(key);
    return sum % SIZE;
}

void insert(char* key)
{   
    int hashIndex = hashFunction(key);

    struct bucket* b = &hashTable[hashIndex];

    if (b->keys == NULL) {
        b->keys = (char**) malloc(sizeof(char*));
        b->keys[0] = (char*) malloc(sizeof(char) * MAX_KEY_LEN);
        strcpy(b->keys[0], key);
        b->num_keys = 1;
    } else {
        int i = b->num_keys - 1;
        while (i >= 0 && strcmp(key, b->keys[i]) < 0) {
            b->keys[i+1] = b->keys[i];
            i--;
        }
        b->keys[i+1] = (char*) malloc(sizeof(char) * MAX_KEY_LEN);
        strcpy(b->keys[i+1], key);
        b->num_keys++;
    }
}

void key_remove(char* key){
    int hashIndex = hashFunction(key);

    struct bucket* b = &hashTable[hashIndex];

    if (b->keys == NULL) {
        return;
    }

    int i = 0;
    while (i < b->num_keys && strcmp(b->keys[i], key) != 0) {
        i++;
    }

    if (i == b->num_keys) {
        return;
    }

    free(b->keys[i]);

    for (int j = i; j < b->num_keys - 1; j++) {
        b->keys[j] = b->keys[j+1];
    }
    b->num_keys--;
}

void display(){
    char result[SIZE][MAX_KEY_LEN];
    int cnt = 0;

    for(int i=SIZE-1; i>= 0; i--){
        struct bucket* b = &hashTable[i];
        for (int j = 0; j < b->num_keys; j++) {
            strcpy(result[cnt], b->keys[j]);
            cnt++;
        }
    }

    for(int i=cnt-1; i>=0; i--)
    {
        printf("%s\n", result[i]);
    }
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