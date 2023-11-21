#include <stdio.h>
#include <stdlib.h>

#include "arrayQueue.h"

// 큐 생성
queue* initQueue(void) {
    queue *q;

    q = (queue*)malloc(sizeof(queue));
    (*q).front = -1;
    (*q).rear = -1;

    return q;
}

// 공백 검사
int isEmpty(queue *q) {
    if (q -> front == q -> rear) {
        printf("Queue is Empty.\n");
        return 1;
    }

    return 0;
}

// 가득 찼는지 검사
int isFull(queue *q) {
    if (q -> rear == QueueSIZE - 1) {
        printf("Queue is Full.\n");
        return 1;
    }

    return 0;
}

// 원소 삽입
void enQueue(queue *q, elem item) {
    if (isFull(q)) {
        return;
    } else {
        q -> rear++;
        q -> queue[q -> rear] = item;
    }
}

// 원소 삭제
elem deQueue(queue *q) {
    if (isEmpty(q)) {
        return '\0';    // return null character. (non-void func should return a value)
    } else {
        q -> front++;
        return q -> queue[q -> front];
    }
}

// front 원소 검색
elem peek(queue *q) {
    if (isEmpty(q)) {
        return '\0';    // return null character. (non-void func should return a value)
    } else {
        return q -> queue[q -> front + 1];
    }
}

// 큐 전체 원소 출력
void printAll(queue *q) {
    printf("Queue: [ ");
    for (int i = q -> front + 1; i <= q -> rear; i++) {
        printf("%c ", q -> queue[i]);
    }
    printf("]\n");
}
