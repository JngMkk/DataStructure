#include <stdio.h>
#include <stdlib.h>

#include "circularQueue.h"

queue* initQueue(void) {
    queue *q;
    q = (queue*)malloc(sizeof(queue));

    (*q).front = 0;
    (*q).rear = 0;

    return q;
}

int isEmpty(queue *q) {
    if ((*q).front == (*q).rear) {
        printf("Queue is Empty.\n");
        return 1;
    } else {
        return 0;
    }
}

int isFull(queue *q) {
    if (((*q).rear + 1) % QueueSIZE == (*q).front) {
        printf("Queue is Full.\n");
        return 1;
    } else {
        return 0;
    }
}

void enQueue(queue *q, elem item) {
    if (isFull(q)) {
        return;
    } else {
        (*q).rear = ((*q).rear + 1) % QueueSIZE;
        (*q).queue[(*q).rear] = item;
    }
}

elem deQueue(queue *q) {
    if (isEmpty(q)) {
        return '\0';
    } else {
        (*q).front = ((*q).front + 1) % QueueSIZE;
        return (*q).queue[(*q).front];
    }
}

elem peek(queue *q) {
    if (isEmpty(q)) {
        return '\0';
    } else {
        return (*q).queue[((*q).front + 1) % QueueSIZE];
    }
}

void printAll(queue *q) {
    int i, front, rear;
    front = ((*q).front + 1) % QueueSIZE;
    rear = ((*q).rear + 1) % QueueSIZE;
    i = front;
    
    printf("Queue [ ");
    while (i != rear) {
        printf("%c ", (*q).queue[i]);
        i = (i + 1) % QueueSIZE;
    }
    printf("]\n");
}
