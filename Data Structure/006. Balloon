/*
문제 번호 : 2346
문제 링크 : https://www.acmicpc.net/problem/2346
컴파일러 버전 : gcc 11.3.1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 2002

typedef struct {
    int first[SIZE];
    int second[SIZE];
    int front;
    int back;
} Deque;

void initDeque(Deque* dq) {
    dq->front = SIZE / 2;
    dq->back = SIZE / 2;
}

// 프로토타입 설정
void push_front(Deque* dq, int index, int value);
void push_back(Deque* dq, int index, int value);
void pop_front(Deque* dq, int* index, int* value);
void pop_back(Deque* dq, int* index, int* value);
int size(Deque* dq);
int empty(Deque* dq);

void push_front(Deque* dq, int index, int value) {
    dq->first[--(dq->front)] = index;
    dq->second[dq->front] = value;
}

void push_back(Deque* dq, int index, int value) {
    dq->first[dq->back] = index;
    dq->second[dq->back] = value;
    dq->back++;
}

void pop_front(Deque* dq, int* index, int* value) {
    if (dq->front == dq->back) return;
    *index = dq->first[dq->front];
    *value = dq->second[dq->front];
    dq->front++;
}

void pop_back(Deque* dq, int* index, int* value) {
    if (dq->front == dq->back) return;
    dq->back--;
    *index = dq->first[dq->back];
    *value = dq->second[dq->back];
}

int size(Deque* dq) { return dq->back - dq->front; }

int empty(Deque* dq) { return dq->front == dq->back; }

int main() {
    int N;
    scanf("%d", &N);

    Deque dq;
    initDeque(&dq);

    for (int i = 1; i <= N; i++) {
        int value;
        scanf("%d", &value);
        push_back(&dq, i, value);
    }

    int index, move;
    pop_front(&dq, &index, &move);
    printf("%d ", index);

    while (!empty(&dq)) {
        int steps = abs(move) % size(&dq);

        if (move > 0) {
            for (int i = 0; i < steps - 1; i++) {
                int temp_index, temp_value;
                pop_front(&dq, &temp_index, &temp_value);
                push_back(&dq, temp_index, temp_value);
            }
        } else {
            for (int i = 0; i < steps; i++) {
                int temp_index, temp_value;
                pop_back(&dq, &temp_index, &temp_value);
                push_front(&dq, temp_index, temp_value);
            }
        }

        pop_front(&dq, &index, &move);
        printf("%d ", index);
    }

    return 0;
}
