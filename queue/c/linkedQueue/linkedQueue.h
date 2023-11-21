#pragma once

typedef char elem;

typedef struct QNode {
    elem data;
    struct QNode *link;
} Node;

typedef struct {
    Node *front, *rear;
} QType;

QType* initQueue(void);
int isEmpty(QType *q);
void enQueue(QType *q, elem item);
elem deQueue(QType *q);
elem peek(QType *q);
void printAll(QType *q);
