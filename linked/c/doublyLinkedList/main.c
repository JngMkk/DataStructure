#include <stdio.h>

#include "doublyLinkedList.h"

int main(void) {
    Head *DL;
    Node *p;

    DL = initHead();
    printList(DL);

    insertNode(DL, NULL, "월");
    printList(DL);

    p = searchNode(DL, "월");
    insertNode(DL, p, "수");
    printList(DL);

    p = searchNode(DL, "수");
    insertNode(DL, p, "금");
    printList(DL);

    deleteNode(DL, p);
    printList(DL);

    return 0;
}

/*
DL = ()
DL = (월)
DL = (월, 수)
DL = (월, 수, 금)
DL = (월, 금)
*/
