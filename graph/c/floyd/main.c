#include <stdio.h>
#include "floyd.h"

int main(void) {
    extern int weight[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            if (weight[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", weight[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
    
    floyd(MAX_VERTICES);
    return 0;
}

