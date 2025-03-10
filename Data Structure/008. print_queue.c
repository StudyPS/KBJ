/*
문제 번호 : 1966
문제 링크 : https://www.acmicpc.net/problem/1966
컴파일러 버전 : gcc 11.3.1
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    int index;
    int priority;
} Document;

typedef struct {
    Document data[SIZE];
    int front, rear;
} Queue;

void initQueue(Queue* q);
int isEmpty(Queue* q);

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

void enqueue(Queue* q, int index, int priority) {
    q->data[q->rear].index = index;
    q->data[q->rear].priority = priority;
    q->rear++;
}

Document dequeue(Queue* q) { return q->data[q->front++]; }

int isEmpty(Queue* q) { return q->front == q->rear; }

int getMaxPriority(Queue* q) {
    int maxPriority = 0;
    for (int i = q->front; i < q->rear; i++) {
        if (q->data[i].priority > maxPriority) {
            maxPriority = q->data[i].priority;
        }
    }
    return maxPriority;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        Queue q;
        initQueue(&q);

        int priorities[SIZE];
        for (int i = 0; i < N; i++) {
            int priority;
            scanf("%d", &priority);
            priorities[i] = priority;
            enqueue(&q, i, priority);
        }

        int printCount = 0;
        while (!isEmpty(&q)) {
            int maxPriority = getMaxPriority(&q);
            Document frontDoc = dequeue(&q);

            if (frontDoc.priority == maxPriority) {
                printCount++;
                if (frontDoc.index == M) {
                    printf("%d\n", printCount);
                    break;
                }
            } else {
                enqueue(&q, frontDoc.index, frontDoc.priority);
            }
        }
    }

    return 0;
}
