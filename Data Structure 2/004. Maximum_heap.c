/*
문제 번호 : 11279
문제 링크 : https://www.acmicpc.net/problem/11279
컴파일러 버전 : gcc 11.3.1
*/
#include <stdio.h>

#define SIZE 100001

int heap[SIZE];
int heap_size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(int x) {
    heap[++heap_size] = x;
    int idx = heap_size;

    while (idx > 1 && heap[idx] > heap[idx / 2]) {
        swap(&heap[idx], &heap[idx / 2]);
        idx /= 2;
    }
}

int pop() {
    if (heap_size == 0) return 0;

    int top = heap[1];
    heap[1] = heap[heap_size--];

    int idx = 1;
    while (1) {
        int left = idx * 2;
        int right = idx * 2 + 1;
        int largest = idx;

        if (left <= heap_size && heap[left] > heap[largest]) largest = left;
        if (right <= heap_size && heap[right] > heap[largest]) largest = right;

        if (largest == idx) break;

        swap(&heap[idx], &heap[largest]);
        idx = largest;
    }

    return top;
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
