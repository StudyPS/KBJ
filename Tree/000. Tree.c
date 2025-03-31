/*
문제 번호 : 6416
문제 링크 : https://www.acmicpc.net/problem/6416
컴파일러 버전 : gcc 11.3.1
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    int parent[MAX + 1];
    int in_degree[MAX + 1];
    bool exists[MAX + 1];
} Graph;

void initGraph(Graph *graph) {
    for (int i = 0; i <= MAX; i++) {
        graph->parent[i] = -1;
        graph->in_degree[i] = 0;
        graph->exists[i] = false;
    }
}

bool isTree(Graph *graph) {
    int rootCount = 0, nodeCount = 0, edgeCount = 0, root = -1;

    // 노드 개수 세기
    for (int i = 1; i <= MAX; i++) {
        if (graph->exists[i]) {
            nodeCount++;
            if (graph->in_degree[i] == 0) {
                rootCount++;
                root = i;
            } else if (graph->in_degree[i] > 1) {
                return false;  // 들어오는 간선이 2개 이상이면 트리가 아님
            }
        }
    }

    if (rootCount != 1) return false;  // 루트가 하나여야 함

    // 루트에서 BFS 수행하여 모든 노드 방문 확인
    bool visited[MAX + 1] = {false};
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = root;
    visited[root] = true;

    int visitedCount = 0;
    while (front < rear) {
        int node = queue[front++];
        visitedCount++;

        for (int i = 1; i <= MAX; i++) {
            if (graph->parent[i] == node && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }

    return visitedCount == nodeCount;
}

int main() {
    int u, v, caseNum = 0;
    Graph graph;

    while (1) {
        initGraph(&graph);
        bool isEmpty = true;
        while (scanf("%d %d", &u, &v) == 2 && !(u == 0 && v == 0)) {
            if (u < 0 && v < 0) return 0;
            graph.exists[u] = graph.exists[v] = true;
            graph.parent[v] = u;
            graph.in_degree[v]++;
            isEmpty = false;
        }

        printf("Case %d is %s tree.\n", ++caseNum,
               (isEmpty || isTree(&graph)) ? "a" : "not a");
    }

    return 0;
}
