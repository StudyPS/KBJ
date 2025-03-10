/*
문제 번호 : 1935
문제 링크 : https://www.acmicpc.net/problem/1935
컴파일러 버전 : gcc 11.3.1
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define LEN 100
#define VAR 26

typedef struct {
    double data[SIZE];
    int top;
} Stack;

void init(Stack *s);
void push(Stack *s, double value);
double pop(Stack *s);

void init(Stack *s) { s->top = -1; }

void push(Stack *s, double value) {
    if (s->top < SIZE - 1) {
        s->data[++(s->top)] = value;
    }
}

double pop(Stack *s) {
    if (s->top >= 0) {
        return s->data[(s->top)--];
    }
    return 0;
}

int main(void) {
    int N;
    char expr[LEN + 1];
    double values[VAR];

    scanf("%d", &N);
    scanf("%s", expr);

    for (int i = 0; i < N; i++) {
        scanf("%lf", &values[i]);
    }

    Stack stack;
    init(&stack);

    // 후위 표기식 처리
    for (int i = 0; i < strlen(expr); i++) {
        char c = expr[i];

        if (isalpha(c)) {
            push(&stack, values[c - 'A']);
        } else {
            double b = pop(&stack);
            double a = pop(&stack);
            double result = 0;

            switch (c) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
            }

            push(&stack, result);  // 계산 결과 다시 push
        }
    }

    // 최종 결과 출력 (소수점 둘째 자리까지)
    printf("%.2lf\n", pop(&stack));

    return 0;
}
