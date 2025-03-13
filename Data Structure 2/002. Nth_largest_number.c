/*
문제 번호 : 2075
문제 링크 : https://www.acmicpc.net/problem/2075
컴파일러 버전 : gcc 11.3.1
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1500

typedef struct {
    int heap[SIZE];
    int size;
} MinHeap;

void insertHeap(MinHeap *h, int value) {
    int i = h->size++;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->heap[parent] <= value) break;
        h->heap[i] = h->heap[parent];
        i = parent;
    }
    h->heap[i] = value;
}

void popHeap(MinHeap *h) {
    int last = h->heap[--h->size];
    int i = 0;
    while (2 * i + 1 < h->size) {
        int left = 2 * i + 1, right = 2 * i + 2, minChild = left;
        if (right < h->size && h->heap[right] < h->heap[left]) {
            minChild = right;
        }
        if (h->heap[minChild] >= last) break;
        h->heap[i] = h->heap[minChild];
        i = minChild;
    }
    h->heap[i] = last;
}

int main() {
    int N;
    scanf("%d", &N);

    MinHeap heap = {.size = 0};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            scanf("%d", &num);
            if (heap.size < N) {
                insertHeap(&heap, num);
            } else if (num > heap.heap[0]) {
                popHeap(&heap);
                insertHeap(&heap, num);
            }
        }
    }

    printf("%d\n", heap.heap[0]);  // N번째 큰 수

    return 0;
}
