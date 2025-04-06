/*
문제 번호 : 14675
문제 링크 : https://www.acmicpc.net/problem/14675
컴파일러 버전 : gcc 11.3.1
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int N, Q;
int degree[MAX_N + 1];  // 각 정점의 차수 저장
int edges[MAX_N][2];    // 입력된 간선 정보 저장

int main() {
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        degree[a]++;
        degree[b]++;
        edges[i][0] = a;
        edges[i][1] = b;
    }

    scanf("%d", &Q);
    while (Q--) {
        int t, k;
        scanf("%d %d", &t, &k);
        if (t == 1) {
            // 단절점: 리프 노드(차수가 1인 노드)가 아니면 yes
            printf("%s\n", (degree[k] > 1) ? "yes" : "no");
        } else {
            // 단절선: 트리의 모든 간선은 단절선
            printf("yes\n");
        }
    }

    return 0;
}
