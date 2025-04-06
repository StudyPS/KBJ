/*
문제 번호 : 1991
문제 링크 : https://www.acmicpc.net/problem/1991
컴파일러 버전 : gcc 11.3.1
*/
#include <stdio.h>

#define MAX 26

// 각각의 노드의 왼쪽, 오른쪽 자식 저장
char left[MAX];
char right[MAX];

void preorder(char node) {
    if (node == '.') return;
    printf("%c", node);           // 루트
    preorder(left[node - 'A']);   // 왼쪽
    preorder(right[node - 'A']);  // 오른쪽
}

void inorder(char node) {
    if (node == '.') return;
    inorder(left[node - 'A']);   // 왼쪽
    printf("%c", node);          // 루트
    inorder(right[node - 'A']);  // 오른쪽
}

void postorder(char node) {
    if (node == '.') return;
    postorder(left[node - 'A']);   // 왼쪽
    postorder(right[node - 'A']);  // 오른쪽
    printf("%c", node);            // 루트
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char root, l, r;
        scanf(" %c %c %c", &root, &l, &r);  // 공백 조심
        left[root - 'A'] = l;
        right[root - 'A'] = r;
    }

    preorder('A');
    printf("\n");
    inorder('A');
    printf("\n");
    postorder('A');
    printf("\n");

    return 0;
}
