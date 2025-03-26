/*
문제 번호 : 21939
문제 링크 : https://www.acmicpc.net/problem/21939
컴파일러 버전 : gcc 11.3.1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100001

typedef struct {
    int level;
    int problem;
} HeapNode;

HeapNode minHeap[MAX_SIZE], maxHeap[MAX_SIZE];
int minSize, maxSize;
int problemLevel[MAX_SIZE];
int exist[MAX_SIZE];

void minPush(int level, int problem) {
    int cur = ++minSize;
    while (cur > 1 && (minHeap[cur / 2].level > level ||
                       (minHeap[cur / 2].level == level &&
                        minHeap[cur / 2].problem > problem))) {
        minHeap[cur] = minHeap[cur / 2];
        cur /= 2;
    }
    minHeap[cur].level = level;
    minHeap[cur].problem = problem;
}

HeapNode minPop() {
    HeapNode top = minHeap[1];
    HeapNode temp = minHeap[minSize--];
    int parent = 1, child = 2;
    while (child <= minSize) {
        if (child < minSize &&
            (minHeap[child].level > minHeap[child + 1].level ||
             (minHeap[child].level == minHeap[child + 1].level &&
              minHeap[child].problem > minHeap[child + 1].problem)))
            child++;
        if (temp.level < minHeap[child].level ||
            (temp.level == minHeap[child].level &&
             temp.problem < minHeap[child].problem))
            break;
        minHeap[parent] = minHeap[child];
        parent = child;
        child *= 2;
    }
    minHeap[parent] = temp;
    return top;
}

void maxPush(int level, int problem) {
    int cur = ++maxSize;
    while (cur > 1 && (maxHeap[cur / 2].level < level ||
                       (maxHeap[cur / 2].level == level &&
                        maxHeap[cur / 2].problem < problem))) {
        maxHeap[cur] = maxHeap[cur / 2];
        cur /= 2;
    }
    maxHeap[cur].level = level;
    maxHeap[cur].problem = problem;
}

HeapNode maxPop() {
    HeapNode top = maxHeap[1];
    HeapNode temp = maxHeap[maxSize--];
    int parent = 1, child = 2;
    while (child <= maxSize) {
        if (child < maxSize &&
            (maxHeap[child].level < maxHeap[child + 1].level ||
             (maxHeap[child].level == maxHeap[child + 1].level &&
              maxHeap[child].problem < maxHeap[child + 1].problem)))
            child++;
        if (temp.level > maxHeap[child].level ||
            (temp.level == maxHeap[child].level &&
             temp.problem > maxHeap[child].problem))
            break;
        maxHeap[parent] = maxHeap[child];
        parent = child;
        child *= 2;
    }
    maxHeap[parent] = temp;
    return top;
}

void syncMinHeap() {
    while (minSize > 0 && !exist[minHeap[1].problem]) {
        minPop();
    }
}

void syncMaxHeap() {
    while (maxSize > 0 && !exist[maxHeap[1].problem]) {
        maxPop();
    }
}

int main() {
    int N, M;
    scanf("%d", &N);

    memset(problemLevel, 0, sizeof(problemLevel));
    memset(exist, 0, sizeof(exist));

    for (int i = 0; i < N; i++) {
        int P, L;
        scanf("%d %d", &P, &L);
        problemLevel[P] = L;
        exist[P] = 1;
        minPush(L, P);
        maxPush(L, P);
    }

    scanf("%d", &M);

    while (M--) {
        char cmd[10];
        scanf("%s", cmd);

        if (strcmp(cmd, "recommend") == 0) {
            int x;
            scanf("%d", &x);
            if (x == 1) {
                syncMaxHeap();
                printf("%d\n", maxHeap[1].problem);
            } else {
                syncMinHeap();
                printf("%d\n", minHeap[1].problem);
            }
        } else if (strcmp(cmd, "add") == 0) {
            int P, L;
            scanf("%d %d", &P, &L);
            problemLevel[P] = L;
            exist[P] = 1;
            minPush(L, P);
            maxPush(L, P);
        } else if (strcmp(cmd, "solved") == 0) {
            int P;
            scanf("%d", &P);
            exist[P] = 0;
        }
    }

    return 0;
}
