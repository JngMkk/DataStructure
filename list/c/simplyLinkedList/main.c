#include <stdio.h>

#include "linkedList.h"

int main(void) {
    Head *L;
    Node *p;

    L = initHead();
    printList(L);

    insertFront(L, "수");
    printList(L);

    insertBack(L, "금");
    printList(L);

    insertFront(L, "월");
    printList(L);

    insertMiddle(L, L -> head, "화");
    printList(L);

    p = searchNode(L, "화");
    if (p != NULL) {
        deleteNode(L, p);   
    }
    printList(L);

    reverse(L);
    printList(L);

    freeMemory(L);
    printList(L);

    return 0;
}

/*
L = ()
L = (수)
L = (수, 금)
L = (월, 수, 금)
L = (월, 화, 수, 금)
L = (월, 수, 금)
L = (금, 수, 월)
L = ()
*/
