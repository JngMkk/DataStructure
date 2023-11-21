#include <stdio.h>
#include <stdlib.h>

#include "linkedQueue.h"

QType* initQueue(void) {
    QType *q;
    q = (QType*)malloc(sizeof(QType));
    (*q).front = NULL;
    (*q).rear = NULL;

    return q;
}

int isEmpty(QType* q) {
    if ((*q).front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void enQueue(QType *q, elem item) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    (*newNode).data = item;
    (*newNode).link = NULL;
    if ((*q).front == NULL) {
        (*q).front = newNode;
        (*q).rear = newNode;
    } else {
        (*(*q).rear).link = newNode;
        (*q).rear = newNode;
    }
}

elem deQueue(QType *q) {
    if (isEmpty(q)) {
        return '\0';
    } else {
        Node *old = (*q).front;
        elem item;
        item = (*old).data;
        (*q).front = (*old).link;
        if ((*q).front == NULL) {
            (*q).rear = NULL;
        }
        free(old);
        
        return item;
    }
}

elem peek(QType *q) {
    if (isEmpty(q)) {
        return '\0';
    } else {
        return (*(*q).front).data;
    }
}

void printAll(QType *q) {
    Node *temp = (*q).front;
    printf("Queue: [ ");
    while (temp) {
        printf("%c ", (*temp).data);
        temp = (*temp).link;
    }
    printf("]\n");
}
