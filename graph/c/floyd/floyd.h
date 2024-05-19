#pragma once

#define INF 10000
#define MAX_VERTICES 5

int graph[MAX_VERTICES][MAX_VERTICES];

void printStep(int n);
void floyd(int n);