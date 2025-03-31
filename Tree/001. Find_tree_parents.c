/*
문제 번호 : 11725
문제 링크 : https://www.acmicpc.net/problem/11725
컴파일러 버전 : gcc 11.3.1
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int nodes[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) { q->front = q->rear = 0; }

bool isEmpty(Queue *q) { return q->front == q->rear; }

void enqueue(Queue *q, int value) { q->nodes[q->rear++] = value; }

int dequeue(Queue *q) { return q->nodes[q->front++]; }

int N;
int tree[MAX + 1][MAX];
int size[MAX + 1];
int parent[MAX + 1];

void bfs(int root) {
    Queue q;
    initQueue(&q);
    enqueue(&q, root);
    parent[root] = -1;  // 루트의 부모는 없음

    while (!isEmpty(&q)) {
        int cur = dequeue(&q);
        for (int i = 0; i < size[cur]; i++) {
            int next = tree[cur][i];
            if (parent[next] == 0) {  // 방문하지 않은 노드
                parent[next] = cur;
                enqueue(&q, next);
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        tree[a][size[a]++] = b;
        tree[b][size[b]++] = a;
    }

    bfs(1);

    for (int i = 2; i <= N; i++) {
        printf("%d\n", parent[i]);
    }

    return 0;
}
