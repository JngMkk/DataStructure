#include "circularLinkedList.h"

int main(void) {
    Head *CL;
    Node *p;

    CL = initHead();
    printList(CL);

    insertFront(CL, "월");
    printList(CL);

    p = searchNode(CL, "월");
    insertMiddle(CL, p, "수");
    printList(CL);

    p = searchNode(CL, "수");
    insertMiddle(CL, p, "금");
    printList(CL);

    p = searchNode(CL, "수");
    deleteNode(CL, p);
    printList(CL);

    return 0;
}
