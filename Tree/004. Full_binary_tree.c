/*
문제 번호 : 9934
문제 링크 : https://www.acmicpc.net/problem/9934
컴파일러 버전 : gcc 11.3.1
*/
#include <math.h>
#include <stdio.h>

#define MAX 1024

int tree[MAX];
int level[10][MAX];  // 각 레벨마다 번호 저장
int level_idx[10];   // 각 레벨의 인덱스

void build(int start, int end, int current_level) {
    if (start > end) return;

    int mid = (start + end) / 2;
    level[current_level][level_idx[current_level]++] = tree[mid];

    build(start, mid - 1, current_level + 1);  // 왼쪽 서브트리
    build(mid + 1, end, current_level + 1);    // 오른쪽 서브트리
}

int main() {
    int K;
    scanf("%d", &K);
    int N = (1 << K) - 1;  // 노드 개수: 2^K - 1

    for (int i = 0; i < N; i++) {
        scanf("%d", &tree[i]);
    }

    // 트리 빌드
    build(0, N - 1, 0);

    // 출력
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < level_idx[i]; j++) {
            printf("%d ", level[i][j]);
        }
        printf("\n");
    }

    return 0;
}
