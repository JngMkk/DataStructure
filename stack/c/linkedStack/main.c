#include <stdio.h>

#include "linkedStack.h"

int main(void) {
    elem item;
    top = NULL;
    
    printAll();
    
    push(1);
    printAll();

    push(2);
    printAll();

    push(3);
    printAll();

    item = peek();
    printAll();
    printf("peek: %d\n", item);

    item = pop();
    printAll();
    printf("pop: %d\n", item);

    item = pop();
    printAll();
    printf("pop: %d\n", item);
    
    item = pop();
    printAll();
    printf("pop: %d\n", item);

    return 0;
}

/*
Stack [ ]
Stack [ 1 ]
Stack [ 2 1 ]
Stack [ 3 2 1 ]
Stack [ 3 2 1 ]
peek: 3
Stack [ 2 1 ]
pop: 3
Stack [ 1 ]
pop: 2
Stack [ ]
pop: 1
*/
