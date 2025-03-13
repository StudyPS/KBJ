/*
문제 번호 : 1620
문제 링크 : https://www.acmicpc.net/problem/1620
컴파일러 버전 : gcc 11.3.1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100000
#define LEN_SIZE 21

typedef struct {
    char name[LEN_SIZE];
    int num;
} Pokemon;

Pokemon name_to_num[SIZE];
char *num_to_name[SIZE + 1];

int compare(const void *a, const void *b) {
    return strcmp(((Pokemon *)a)->name, ((Pokemon *)b)->name);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", name_to_num[i].name);
        name_to_num[i].num = i + 1;
        num_to_name[i + 1] = name_to_num[i].name;
    }

    qsort(name_to_num, N, sizeof(Pokemon), compare);

    char query[LEN_SIZE];
    for (int i = 0; i < M; i++) {
        scanf("%s", query);

        if (query[0] >= '0' && query[0] <= '9') {
            int idx = atoi(query);
            printf("%s\n", num_to_name[idx]);
        } else {
            Pokemon key;
            strcpy(key.name, query);
            Pokemon *result = (Pokemon *)bsearch(&key, name_to_num, N,
                                                 sizeof(Pokemon), compare);
            if (result) {
                printf("%d\n", result->num);
            }
        }
    }

    return 0;
}
