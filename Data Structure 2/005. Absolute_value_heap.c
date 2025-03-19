/*
문제 번호 : 11286
문제 링크 : https://www.acmicpc.net/problem/11286
컴파일러 버전 : gcc 11.3.1
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int abs_value;
} HeapNode;

HeapNode heap[100001];
int size = 0;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

int compare(HeapNode a, HeapNode b) {
    if (a.abs_value == b.abs_value) {
        return a.value > b.value;  // 같으면 작은 값 우선
    }
    return a.abs_value > b.abs_value;
}

void push(int x) {
    heap[++size].value = x;
    heap[size].abs_value = (x < 0) ? -x : x;

    int cur = size;
    while (cur > 1 && compare(heap[cur / 2], heap[cur])) {
        swap(&heap[cur / 2], &heap[cur]);
        cur /= 2;
    }
}

int pop() {
    if (size == 0) return 0;
    int res = heap[1].value;
    heap[1] = heap[size--];

    int cur = 1;
    while (1) {
        int left = cur * 2;
        int right = cur * 2 + 1;
        int next = cur;

        if (left <= size && compare(heap[next], heap[left])) {
            next = left;
        }
        if (right <= size && compare(heap[next], heap[right])) {
            if (compare(heap[left], heap[right]))
                next = right;
            else
                next = left;
        }
        if (next == cur) break;

        swap(&heap[cur], &heap[next]);
        cur = next;
    }
    return res;
}

int main() {
    int N, x;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        if (x == 0) {
            printf("%d\n", pop());
        } else {
            push(x);
        }
    }
    return 0;
}
