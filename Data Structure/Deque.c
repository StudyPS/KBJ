/*
문제 번호 : 10866
문제 링크 : https://www.acmicpc.net/problem/10866
컴파일러 버전 : gcc 11.3.1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10000

typedef struct {
    int data[SIZE];
    int front;
    int back;
} Deque;

void initDeque(Deque* dq) {
    dq->front = SIZE / 2;
    dq->back = SIZE / 2;
}

// 프로토타입 설정
void push_front(Deque* dq, int x);
void push_back(Deque* dq, int x);
int pop_front(Deque* dq);
int pop_back(Deque* dq);
int size(Deque* dq);
int empty(Deque* dq);
int front(Deque* dq);
int back(Deque* dq);

void push_front(Deque* dq, int x) { dq->data[--(dq->front)] = x; }

void push_back(Deque* dq, int x) { dq->data[(dq->back)++] = x; }

int pop_front(Deque* dq) {
    if (dq->front == dq->back) return -1;  // 비어있음
    return dq->data[(dq->front)++];
}

int pop_back(Deque* dq) {
    if (dq->front == dq->back) return -1;  // 비어있음
    return dq->data[--(dq->back)];
}

int size(Deque* dq) { return dq->back - dq->front; }

int empty(Deque* dq) { return dq->front == dq->back ? 1 : 0; }

int front(Deque* dq) {
    if (dq->front == dq->back) return -1;
    return dq->data[dq->front];
}

int back(Deque* dq) {
    if (dq->front == dq->back) return -1;
    return dq->data[dq->back - 1];
}

int main() {
    int N;
    scanf("%d", &N);

    Deque dq;
    initDeque(&dq);

    char command[20];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", command);

        if (strcmp(command, "push_front") == 0) {
            scanf("%d", &x);
            push_front(&dq, x);
        } else if (strcmp(command, "push_back") == 0) {
            scanf("%d", &x);
            push_back(&dq, x);
        } else if (strcmp(command, "pop_front") == 0) {
            printf("%d\n", pop_front(&dq));
        } else if (strcmp(command, "pop_back") == 0) {
            printf("%d\n", pop_back(&dq));
        } else if (strcmp(command, "size") == 0) {
            printf("%d\n", size(&dq));
        } else if (strcmp(command, "empty") == 0) {
            printf("%d\n", empty(&dq));
        } else if (strcmp(command, "front") == 0) {
            printf("%d\n", front(&dq));
        } else if (strcmp(command, "back") == 0) {
            printf("%d\n", back(&dq));
        }
    }

    return 0;
}
