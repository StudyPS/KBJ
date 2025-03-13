/*
문제 번호 : 14425
문제 링크 : https://www.acmicpc.net/problem/14425
컴파일러 버전 : gcc 11.3.1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 501
#define HASH_SIZE 200003  // 소수로 설정하면 충돌이 줄어듦

typedef struct Node {
    char str[MAX_STR_LEN];
    struct Node *next;
} Node;

Node *hash_table[HASH_SIZE];

unsigned int hash(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % HASH_SIZE;
}

void insert(const char *str) {
    unsigned int idx = hash(str);
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->str, str);
    new_node->next = hash_table[idx];
    hash_table[idx] = new_node;
}

int search(const char *str) {
    unsigned int idx = hash(str);
    Node *cur = hash_table[idx];
    while (cur) {
        if (strcmp(cur->str, str) == 0) {
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

void free_table() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *cur = hash_table[i];
        while (cur) {
            Node *temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    char str[MAX_STR_LEN];
    for (int i = 0; i < N; i++) {
        scanf("%s", str);
        insert(str);
    }

    int count = 0;
    for (int i = 0; i < M; i++) {
        scanf("%s", str);
        if (search(str)) {
            count++;
        }
    }

    printf("%d\n", count);

    free_table();

    return 0;
}
