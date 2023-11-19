#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "doublyLinkedList.h"

Head* initHead(void) {
    Head *DL;
    DL = (Head*)malloc(sizeof(Head));
    DL -> head = NULL;
    return DL;
}

void printList(Head *DL) {
    Node *p;

    printf("DL = (");
    p = DL -> head;
    while (p != NULL) {
        printf("%s", p -> data);
        p = p -> rLink;
        if (p != NULL) {
            printf(", ");
        }
    }
    printf(")\n");
}

void insertNode(Head *DL, Node *pre, char *x) {
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode -> data, x);

    if (DL -> head == NULL) {
        newNode -> rLink = NULL;
        newNode -> lLink = NULL;
        DL -> head = newNode;
    } else {
        newNode -> rLink = pre -> rLink;
        pre -> rLink = newNode;
        newNode -> lLink = pre;
        if (newNode -> rLink != NULL) {
            newNode -> rLink -> lLink = newNode;
        }
    }
}

void deleteNode(Head *DL, Node *old) {
    if (DL -> head == NULL) {
        return;
    } else if (old == NULL) {
        return;
    } else {
        old -> lLink -> rLink = old -> rLink;
        old -> rLink -> lLink = old -> lLink;
        free(old);
    }
}

Node* searchNode(Head *DL, char *x) {
    Node *temp;
    temp = DL -> head;
    while (temp != NULL) {
        if (strcmp(temp -> data, x) == 0) {
            return temp;
        } else {
            temp = temp -> rLink;
        }
    }

    return temp;
}
