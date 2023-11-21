#include <stdio.h>

#include "linkedQueue.h"

int main(void) {
    QType *q = initQueue();
    elem data;

    enQueue(q, 'A');
    printAll(q);
    enQueue(q, 'B');
    printAll(q);
    enQueue(q, 'C');
    printAll(q);
    enQueue(q, 'D');
    printAll(q);

    data = peek(q);
    printf("peek: %c\n", data);

    data = deQueue(q);
    printf("dequeue: %c\n", data);
    printAll(q);
    data = deQueue(q);
    printf("dequeue: %c\n", data);
    printAll(q);
    data = deQueue(q);
    printf("dequeue: %c\n", data);
    printAll(q);

    enQueue(q, 'D');
    printAll(q);
    enQueue(q, 'E');
    printAll(q);

    return 0;
}

/*
Queue: [ A ]
Queue: [ A B ]
Queue: [ A B C ]
Queue: [ A B C D ]
peek: A
dequeue: A
Queue: [ B C D ]
dequeue: B
Queue: [ C D ]
dequeue: C
Queue: [ D ]
Queue: [ D D ]
Queue: [ D D E ]
*/
