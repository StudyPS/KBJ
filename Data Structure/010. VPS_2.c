/*
문제 번호 : 2504
문제 링크 : https://www.acmicpc.net/problem/2504
컴파일러 버전 : gcc 11.3.1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char bracket;
    int value;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

void push(Stack *stack, char bracket, int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    node->bracket = bracket;
    node->value = value;
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack *stack, char expected_bracket, int *accumulated_value) {
    if (!stack->top) return 0;

    int temp = 0;
    while (stack->top && stack->top->bracket != expected_bracket) {
        if (stack->top->bracket == '(' || stack->top->bracket == '[') {
            return 0;
        }
        temp += stack->top->value;
        Node *node = stack->top;
        stack->top = node->next;
        free(node);
    }

    if (!stack->top) return 0;

    Node *node = stack->top;
    stack->top = node->next;
    free(node);

    *accumulated_value = (temp == 0) ? (expected_bracket == '(' ? 2 : 3)
                                     : temp * (expected_bracket == '(' ? 2 : 3);
    return 1;
}

int is_empty(Stack *stack) { return stack->top == NULL; }

int compute_bracket_value(char *string) {
    Stack stack = {NULL};

    for (int i = 0; i < strlen(string); i++) {
        char ch = string[i];

        if (ch == '(' || ch == '[') {
            push(&stack, ch, 0);
        } else if (ch == ')') {
            int value = 0;
            if (!pop(&stack, '(', &value)) return 0;
            push(&stack, '#', value);
        } else if (ch == ']') {
            int value = 0;
            if (!pop(&stack, '[', &value)) return 0;
            push(&stack, '#', value);
        }
    }

    int total = 0;
    while (!is_empty(&stack)) {
        if (stack.top->bracket == '(' || stack.top->bracket == '[') return 0;
        total += stack.top->value;
        Node *node = stack.top;
        stack.top = node->next;
        free(node);
    }

    return total;
}

int main(void) {
    char input[31];
    scanf("%s", input);

    int result = compute_bracket_value(input);
    printf("%d\n", result);

    return 0;
}
