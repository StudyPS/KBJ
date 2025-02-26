/*
문제 번호 : 10828
문제 링크 : https://www.acmicpc.net/problem/10828
컴파일러 버전 : gcc 11.3.1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

void push(Stack *stack, int data);
int pop(Stack *stack);
int show_top(Stack *stack);
int size(Stack *stack);
int empty(Stack *stack);

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

int show_top(Stack *stack) {
    if (stack->top == NULL) {
        return -1;
    }
    Node *cur = stack->top;
    return cur->data;
}

int size(Stack *stack) {
    int i = 0;
    Node *cur = stack->top;
    while (cur != NULL) {
        i++;
        cur = cur->next;
    }
    return i;
}

int empty(Stack *stack) {
    if (stack->top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    char command[10];
    int x, i;
    Stack stack;
    stack.top = NULL;
    scanf("%d", &i);
    while (i--) {
        if (scanf("%s", command) == 1) {
            if (strcmp(command, "push") == 0) {
                if (scanf("%d", &x) == 1) {
                    push(&stack, x);
                }
            } else if (strcmp(command, "pop") == 0) {
                printf("%d\n", pop(&stack));
            } else if (strcmp(command, "size") == 0) {
                printf("%d\n", size(&stack));
            } else if (strcmp(command, "empty") == 0) {
                printf("%d\n", empty(&stack));
            } else if (strcmp(command, "top") == 0) {
                printf("%d\n", show_top(&stack));
            }
        } else {
            printf("Invalid command.\n");
        }
    }
}
