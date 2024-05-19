#include <stdio.h>
#include "floyd.h"
#include "graph.h"

void printStep(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", graph[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void floyd(int n) {
    for (int v = 0; v < n; v++) {
        for (int w = 0; w < n; w++) {
            graph[v][w] = weight[v][w];
        }
    }

    printStep(n);

    for (int k = 0; k < n; k++) {
        for (int v = 0; v < n; v++) {
            for (int w = 0; w < n; w++) {
                if (graph[v][k] + graph[k][w] < graph[v][w]) {
                    graph[v][w] = graph[v][k] + graph[k][w];
                }
            }
        }
        printStep(n);
    }
}

