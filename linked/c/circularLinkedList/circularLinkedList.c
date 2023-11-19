#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "circularLinkedList.h"

Head* initHead(void) {
    Head *CL;
    CL = (Head*)malloc(sizeof(Head));
    CL -> head = NULL;
    return CL;
}

// 리스트 출력
void printList(Head *CL) {
    Node *p;

    printf("CL = (");
    p = CL -> head;
    if (p == NULL) {
        printf(")\n");
        return;
    }
    do {
        printf("%s", p -> data);
        p = p -> link;
        if (p != CL -> head) {
            printf(", ");
        }
    } while (p != CL -> head);
 
    printf(")\n");
}

// 첫 번째 노드 삽입
void insertFront(Head *CL, char *x) {
    Node *newNode, *temp;
    newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode -> data, x);

    if (CL -> head == NULL) {
        CL -> head = newNode;
        newNode -> link = newNode;
    } else {
        temp = CL -> head;
        while (temp -> link != CL -> head) {
            temp = temp -> link;
        }

        newNode -> link = temp -> link;
        temp -> link = newNode;
        CL -> head = newNode;
    }
}

// pre 뒤에 노드 삽입
void insertMiddle(Head *CL, Node *pre, char *x) {
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode -> data, x);

    if (CL -> head == NULL) {
        CL -> head = newNode;
        newNode -> link = newNode;
    } else {
        newNode -> link = pre -> link;
        pre -> link = newNode;
    }
}

// 노드 삭제
void deleteNode(Head *CL, Node *old) {
    Node *pre;

    if (CL -> head == NULL) {
        return;
    }

    if (CL -> head -> link == CL -> head) {
        free(CL -> head);
        CL -> head = NULL;
        return;
    } else if (old == NULL) {
        return;
    } else {
        pre = CL -> head;
        while (pre -> link != old) {
            pre = pre -> link;
        }
        
        pre -> link = old -> link;
        if (old == CL -> head) {
            CL -> head = old -> link;
        }
        free(old);
    }
}

// x 노드 탐색
Node* searchNode(Head *CL, char *x) {
    Node *temp;

    temp = CL -> head;
    if (temp == NULL) {
        return NULL;
    }

    do {
        if (strcmp(temp -> data, x) == 0) {
            return temp;
        } else {
            temp = temp -> link;
        }
    } while (temp != CL -> head);

    return NULL;
}
