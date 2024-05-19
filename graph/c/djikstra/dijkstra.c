#include <stdio.h>
#include "graph.h"
#include "dijkstra.h"

int findNextVertex(int n) {
    int min = INF;
    int minPos = -1;

    for (int i = 0; i < n; i++) {
        if ((distance[i] < min) && !visitied[i]) {
            min = distance[i];
            minPos = i;
        }
    }

    return minPos;
}

void printStep() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (distance[i] == INF) {
            printf("%4c", '*');
        } else {
            printf("%4d", distance[i]);
        }
    }
    printf("\n");
}

void dijkstra(int start, int n) {
    // 시작 정점에서 다른 정점들까지의 거리 초기화
    for (int i = 0; i < n; i++) {
        distance[i] = weight[start][i];
        visitied[i] = FALSE;
    }

    visitied[start] = TRUE;
    distance[start] = 0;
    printStep();

    for (int i = 0; i < n - 1; i++) {
        int u = findNextVertex(n);                              // 다음 정점 u 찾기
        visitied[u] = TRUE;                                     // 방문 처리
        for (int w = 0; w < n; w++) {
            if (!visitied[w]) {                                 // 방문하지 않은 정점 중
                if (distance[u] + weight[u][w] < distance[w]) { // u를 거쳐서 w로 가는 것이 더 짧은 경우
                    distance[w] = distance[u] + weight[u][w];   // 최단 거리 갱신
                }
            }
        }

        printStep();
    }
}