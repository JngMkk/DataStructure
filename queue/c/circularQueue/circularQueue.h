#pragma once

#define QueueSIZE 4

typedef char elem;

typedef struct {
    elem queue[QueueSIZE];
    int front, rear;
} queue;

queue* initQueue(void);
int isEmpty(queue *q);
int isFull(queue *q);
void enQueue(queue *q, elem item);
elem deQueue(queue *q);
elem peek(queue *q);
void printAll(queue *q);
