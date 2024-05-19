#include <stdio.h>
#include "dijkstra.h"

int main(void) {
    int i, j;
    extern int weight[MAX_VERTICES][MAX_VERTICES];
    
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            if (weight[i][j] == INF) {
                printf("%4c", '*');
            } else {
                printf("%4d", weight[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n");
    dijkstra(0, MAX_VERTICES);
    return 0;
}