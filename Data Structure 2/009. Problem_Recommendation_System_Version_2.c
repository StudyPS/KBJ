/*
문제 번호 : 21944
문제 링크 : https://www.acmicpc.net/problem/21944
컴파일러 버전 : gcc 11.3.1

정답을 찾지 못함
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100001

typedef struct {
    int level, problem, group;
} HeapNode;

HeapNode minHeap[MAX_SIZE], maxHeap[MAX_SIZE];
HeapNode groupMinHeap[101][MAX_SIZE], groupMaxHeap[101][MAX_SIZE];
int minSize, maxSize, groupMinSize[101], groupMaxSize[101];
int problemLevel[MAX_SIZE][2];  // 문제 번호 -> (난이도, 알고리즘 그룹)
int exist[MAX_SIZE];            // 문제 존재 여부

void push(HeapNode heap[], int *size, int level, int problem, int group,
          int maxHeap) {
    int cur = ++(*size);
    while (cur > 1) {
        int parent = cur / 2;
        int cmp = maxHeap ? (heap[parent].level < level ||
                             (heap[parent].level == level &&
                              heap[parent].problem < problem))
                          : (heap[parent].level > level ||
                             (heap[parent].level == level &&
                              heap[parent].problem > problem));
        if (!cmp) break;
        heap[cur] = heap[parent];
        cur = parent;
    }
    heap[cur] = (HeapNode){level, problem, group};
}

HeapNode pop(HeapNode heap[], int *size, int maxHeap) {
    HeapNode top = heap[1];
    HeapNode temp = heap[(*size)--];
    int parent = 1, child = 2;
    while (child <= *size) {
        if (child < *size) {
            int cmp = maxHeap
                          ? (heap[child].level < heap[child + 1].level ||
                             (heap[child].level == heap[child + 1].level &&
                              heap[child].problem < heap[child + 1].problem))
                          : (heap[child].level > heap[child + 1].level ||
                             (heap[child].level == heap[child + 1].level &&
                              heap[child].problem > heap[child + 1].problem));
            if (cmp) child++;
        }
        int cmp = maxHeap ? (temp.level > heap[child].level ||
                             (temp.level == heap[child].level &&
                              temp.problem > heap[child].problem))
                          : (temp.level < heap[child].level ||
                             (temp.level == heap[child].level &&
                              temp.problem < heap[child].problem));
        if (cmp) break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return top;
}

void syncHeap(HeapNode heap[], int *size) {
    while (*size > 0 && !exist[heap[1].problem]) {
        pop(heap, size, heap == maxHeap || heap == groupMaxHeap[heap[1].group]);
    }
}

void syncGroupHeap(int G) {
    syncHeap(groupMaxHeap[G], &groupMaxSize[G]);
    syncHeap(groupMinHeap[G], &groupMinSize[G]);
}

int main() {
    int N, M;
    scanf("%d", &N);

    memset(problemLevel, 0, sizeof(problemLevel));
    memset(exist, 0, sizeof(exist));

    for (int i = 0; i < N; i++) {
        int P, L, G;
        scanf("%d %d %d", &P, &L, &G);
        problemLevel[P][0] = L;
        problemLevel[P][1] = G;
        exist[P] = 1;
        push(minHeap, &minSize, L, P, G, 0);
        push(maxHeap, &maxSize, L, P, G, 1);
        push(groupMinHeap[G], &groupMinSize[G], L, P, G, 0);
        push(groupMaxHeap[G], &groupMaxSize[G], L, P, G, 1);
    }

    scanf("%d", &M);

    while (M--) {
        char cmd[15];
        scanf("%s", cmd);

        if (strcmp(cmd, "recommend") == 0) {
            int G, x;
            scanf("%d %d", &G, &x);
            syncGroupHeap(G);
            printf("%d\n", x == 1 ? groupMaxHeap[G][1].problem
                                  : groupMinHeap[G][1].problem);
        } else if (strcmp(cmd, "recommend2") == 0) {
            int x;
            scanf("%d", &x);
            syncHeap(x == 1 ? maxHeap : minHeap, x == 1 ? &maxSize : &minSize);
            printf("%d\n", x == 1 ? maxHeap[1].problem : minHeap[1].problem);
        } else if (strcmp(cmd, "recommend3") == 0) {
            int x, L;
            scanf("%d %d", &x, &L);
            int res = -1;
            for (int i = 1; i <= 100; i++) {
                syncGroupHeap(i);
                if (x == 1 && groupMinSize[i] &&
                    groupMinHeap[i][1].level >= L) {
                    if (res == -1 || groupMinHeap[i][1].problem < res)
                        res = groupMinHeap[i][1].problem;
                }
                if (x == -1 && groupMaxSize[i] &&
                    groupMaxHeap[i][1].level < L) {
                    if (res == -1 || groupMaxHeap[i][1].problem > res)
                        res = groupMaxHeap[i][1].problem;
                }
            }
            printf("%d\n", res);
        } else if (strcmp(cmd, "add") == 0) {
            int P, L, G;
            scanf("%d %d %d", &P, &L, &G);
            problemLevel[P][0] = L;
            problemLevel[P][1] = G;
            exist[P] = 1;
            push(minHeap, &minSize, L, P, G, 0);
            push(maxHeap, &maxSize, L, P, G, 1);
            push(groupMinHeap[G], &groupMinSize[G], L, P, G, 0);
            push(groupMaxHeap[G], &groupMaxSize[G], L, P, G, 1);
        } else if (strcmp(cmd, "solved") == 0) {
            int P;
            scanf("%d", &P);
            exist[P] = 0;
        }
    }

    return 0;
}
