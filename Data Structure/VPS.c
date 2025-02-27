/*
문제 번호 : 9012
문제 링크 : https://www.acmicpc.net/problem/9012
컴파일러 버전 : gcc 11.3.1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

void push(Stack *stack, char data);
int pop(Stack *stack);
int is_empty(Stack *stack);
int check_VPS(char *string);

void push(Stack *stack, char data) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack *stack) {
    if (stack->top == NULL) {
        return 0;
    }
    Node *node = stack->top;
    stack->top = node->next;
    free(node);
    return 1;
}

int is_empty(Stack *stack) { return stack->top == NULL; }

int check_VPS(char *string) {
    Stack stack = {NULL};

    for (int i = 0; i < strlen(string); i++) {
        char ch = string[i];
        if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            if (!pop(&stack)) {
                return 0;
            }
        }
    }

    return is_empty(&stack);
}

int main(void) {
    int n;
    scanf("%d", &n);

    while (n--) {
        char command[50];
        scanf("%s", command);

        if (check_VPS(command)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
