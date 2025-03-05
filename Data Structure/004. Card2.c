/*
문제 번호 : 2164
문제 링크 : https://www.acmicpc.net/problem/2164
컴파일러 버전 : gcc 11.3.1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
} CircularQueue;

int isEmpty(CircularQueue *queue);
int isFull(CircularQueue *queue);
void enqueue(CircularQueue *queue, int value);
int dequeue(CircularQueue *queue);
int peek(CircularQueue *queue);
void Card(int N);

CircularQueue *createQueue(int size) {
    CircularQueue *queue = (CircularQueue *)malloc(sizeof(CircularQueue));
    queue->data = (int *)malloc(size * sizeof(int));
    queue->capacity = size;
    queue->front = queue->rear = -1;
    return queue;
}

int isEmpty(CircularQueue *queue) { return queue->front == -1; }

int isFull(CircularQueue *queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

void enqueue(CircularQueue *queue, int value) {
    if (isFull(queue)) return;
    if (isEmpty(queue)) queue->front = 0;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = value;
}

int dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) return -1;
    int value = queue->data[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % queue->capacity;
    return value;
}

int peek(CircularQueue *queue) {
    if (isEmpty(queue)) return -1;
    return queue->data[queue->front];
}

void Card(int N) {
    CircularQueue *queue = createQueue(N);

    for (int i = 1; i <= N; i++) {
        enqueue(queue, i);
    }

    while (queue->front != queue->rear) {
        dequeue(queue);
        enqueue(queue, dequeue(queue));
    }

    printf("%d\n", peek(queue));

    free(queue->data);
    free(queue);
}

int main() {
    int N;
    scanf("%d", &N);

    Card(N);

    return 0;
}
