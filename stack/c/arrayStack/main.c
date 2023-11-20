#include <stdio.h>

#include "arrayStack.h"

int main(void) {
    elem item;
    
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
