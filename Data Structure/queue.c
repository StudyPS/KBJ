/*
문제 번호 : 18258
문제 링크 : https://www.acmicpc.net/problem/18258
컴파일러 버전 : gcc 11.3.1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

typedef int element;

typedef struct {
    element data[SIZE];
    int rear, front;
} QueueType;

void init(QueueType *Q);
int is_empty(QueueType *Q);
int is_full(QueueType *Q);
void enqueue(QueueType *Q, element e);
void dequeue(QueueType *Q);
void queue_size(QueueType *Q);
void queue_front(QueueType *Q);
void queue_back(QueueType *Q);

void init(QueueType *Q) { Q->rear = Q->front = -1; }

int is_empty(QueueType *Q) {
    if (Q->front == Q->rear) {
        printf("1\n");
        return 1;
    }
    printf("0\n");

    return 0;
}

int is_full(QueueType *Q) {
    if (Q->rear == SIZE - 1) {
        printf("-1\n");
        return 1;
    }
    printf("0\n");

    return 0;
}

void enqueue(QueueType *Q, element e) {
    Q->rear++;
    Q->data[Q->rear] = e;
}

void dequeue(QueueType *Q) {
    if (Q->front == Q->rear) {
        printf("-1\n");
        return;
    } else {
        Q->front++;
        printf("%d\n", Q->data[Q->front]);
    }
}

void queue_size(QueueType *Q) { printf("%d\n", Q->rear - Q->front); }

void queue_front(QueueType *Q) {
    if (Q->front == Q->rear) {
        printf("-1\n");
    } else {
        printf("%d\n", Q->data[Q->front + 1]);
    }
}

void queue_back(QueueType *Q) {
    if (Q->front == Q->rear) {
        printf("-1\n");
    } else {
        printf("%d\n", Q->data[Q->rear]);
    }
}

int main() {
    char command[10];
    int x, i;
    QueueType Q;
    init(&Q);
    scanf("%d", &i);
    while (i--) {
        if (scanf("%s", command) == 1) {
            if (strcmp(command, "push") == 0) {
                if (scanf("%d", &x) == 1) {
                    enqueue(&Q, x);
                } else {
                    printf("Invalid input for push\n");
                }
            } else if (strcmp(command, "pop") == 0) {
                dequeue(&Q);
            } else if (strcmp(command, "size") == 0) {
                queue_size(&Q);
            } else if (strcmp(command, "empty") == 0) {
                is_empty(&Q);
            } else if (strcmp(command, "front") == 0) {
                queue_front(&Q);
            } else if (strcmp(command, "back") == 0) {
                queue_back(&Q);
            } else {
                printf("Invalid command.\n");
            }
        }
    }
    return 0;
}
