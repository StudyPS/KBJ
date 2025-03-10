/*
문제 번호 : 1874
문제 링크 : https://www.acmicpc.net/problem/1874
컴파일러 버전 : gcc 11.3.1
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

void push(Stack *stack, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack *stack) {
    if (stack->top == NULL) {
        return -1;
    }
    Node *node = stack->top;
    int data = node->data;
    stack->top = node->next;
    free(node);
    return data;
}

int main() {
    int n, target, num = 1;
    char result[200000];
    int resultIdx = 0;

    Stack stack;
    stack.top = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &target);

        while (num <= target) {
            push(&stack, num++);
            result[resultIdx++] = '+';
        }

        if (stack.top != NULL && stack.top->data == target) {
            pop(&stack);
            result[resultIdx++] = '-';
        } else {
            printf("NO\n");
            return 0;
        }
    }

    for (int i = 0; i < resultIdx; i++) {
        printf("%c\n", result[i]);
    }

    return 0;
}
