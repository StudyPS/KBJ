/*
문제 번호 : 7662
문제 링크 : https://www.acmicpc.net/problem/7662
컴파일러 버전 : gcc 11.3.1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000001

typedef struct {
    int val;
    int idx;
} HeapNode;

HeapNode minHeap[MAX_SIZE], maxHeap[MAX_SIZE];
int minSize, maxSize;
int visited[MAX_SIZE];
int nodeIdx;

void minPush(int val, int idx) {
    int cur = ++minSize;
    while (cur > 1 && minHeap[cur / 2].val > val) {
        minHeap[cur] = minHeap[cur / 2];
        cur /= 2;
    }
    minHeap[cur].val = val;
    minHeap[cur].idx = idx;
}

HeapNode minPop() {
    HeapNode top = minHeap[1];
    HeapNode temp = minHeap[minSize--];
    int parent = 1, child = 2;
    while (child <= minSize) {
        if (child < minSize && minHeap[child].val > minHeap[child + 1].val)
            child++;
        if (temp.val <= minHeap[child].val) break;
        minHeap[parent] = minHeap[child];
        parent = child;
        child *= 2;
    }
    minHeap[parent] = temp;
    return top;
}

void maxPush(int val, int idx) {
    int cur = ++maxSize;
    while (cur > 1 && maxHeap[cur / 2].val < val) {
        maxHeap[cur] = maxHeap[cur / 2];
        cur /= 2;
    }
    maxHeap[cur].val = val;
    maxHeap[cur].idx = idx;
}

HeapNode maxPop() {
    HeapNode top = maxHeap[1];
    HeapNode temp = maxHeap[maxSize--];
    int parent = 1, child = 2;
    while (child <= maxSize) {
        if (child < maxSize && maxHeap[child].val < maxHeap[child + 1].val)
            child++;
        if (temp.val >= maxHeap[child].val) break;
        maxHeap[parent] = maxHeap[child];
        parent = child;
        child *= 2;
    }
    maxHeap[parent] = temp;
    return top;
}

void syncMinHeap() {
    while (minSize > 0 && visited[minHeap[1].idx]) {
        minPop();
    }
}

void syncMaxHeap() {
    while (maxSize > 0 && visited[maxHeap[1].idx]) {
        maxPop();
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int k;
        scanf("%d", &k);

        // 초기화
        minSize = maxSize = nodeIdx = 0;
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < k; i++) {
            char op;
            int num;
            scanf(" %c %d", &op, &num);

            if (op == 'I') {
                minPush(num, nodeIdx);
                maxPush(num, nodeIdx);
                nodeIdx++;
            } else if (op == 'D') {
                if (num == 1) {  // 최댓값 삭제
                    syncMaxHeap();
                    if (maxSize > 0) {
                        visited[maxHeap[1].idx] = 1;
                        maxPop();
                    }
                } else {  // 최솟값 삭제
                    syncMinHeap();
                    if (minSize > 0) {
                        visited[minHeap[1].idx] = 1;
                        minPop();
                    }
                }
            }
        }

        syncMinHeap();
        syncMaxHeap();

        if (minSize == 0 || maxSize == 0) {
            printf("EMPTY\n");
        } else {
            printf("%d %d\n", maxHeap[1].val, minHeap[1].val);
        }
    }
    return 0;
}
