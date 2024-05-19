#pragma once

#define TRUE 1
#define FALSE 0
#define INF 10000
#define MAX_VERTICES 5 // 정점 개수

int distance[MAX_VERTICES];
int visitied[MAX_VERTICES];

int findNextVertex(int n);
void printStep();
void dijkstra(int start, int n);