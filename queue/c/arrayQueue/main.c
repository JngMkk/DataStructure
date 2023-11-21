#include <stdio.h>

#include "arrayQueue.h"

int main(void) {
    queue *q = initQueue();
    elem data;

    enQueue(q, 'A');
    printAll(q);
    enQueue(q, 'B');
    printAll(q);
    enQueue(q, 'C');
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
peek: A
dequeue: A
Queue: [ B C ]
dequeue: B
Queue: [ C ]
dequeue: C
Queue: [ ]
Queue: [ D ]
Queue is Full.
Queue: [ D ]
*/
