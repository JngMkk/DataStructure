#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedList.h"

// 공백 연결 리스트를 생성
Head* initHead(void) {
    Head *L;
    L = (Head*)malloc(sizeof(Head));
    L -> head = NULL;
    
    return L;
}

// 연결 리스트의 전체 메모리를 해제
void freeMemory(Head *L) {
    Node *p;
    while (L -> head != NULL) {
        p = L -> head;
        L -> head = L -> head -> link;
        free(p);
        p = NULL;
    }
}

// 연결 리스트 출력
void printList(Head *L) {
    Node *p;
    p = L -> head;

    printf("L = (");
    while (p != NULL) {
        printf("%s", p -> data);
        p = p -> link;
        if (p != NULL) {
            printf(", ");
        }
    }

    printf(")\n");
}

// 첫 번째 노드로 삽입
void insertFront(Head *L, char *x) {
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode -> data, x);                     // 새 노드의 데이터 필드에 x 저장
    newNode -> link = L -> head;
    L -> head = newNode;
}

// 노드를 pre 뒤에 삽입
void insertMiddle(Head *L, Node *pre, char *x) {
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode -> data, x);
 
    if (L -> head == NULL) {    // 공백 리스트일 경우
        newNode -> link = NULL;
        L -> head = newNode;
    } else if (pre == NULL) {
        newNode -> link = L -> head;
        L -> head = newNode;
    } else {
        newNode -> link = pre -> link;
        pre -> link = newNode;
    }
}

// 마지막 노드로 삽입
void insertBack(Head *L, char *x) {
    Node *temp;
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode -> data, x);

    newNode -> link = NULL;
    if (L -> head == NULL) {
        L -> head = newNode;
        return;
    }

    temp = L -> head;
    while (temp -> link != NULL) {
        temp = temp -> link;
    }
    temp -> link = newNode;
}

// 리스트에서 노드 p 삭제
void deleteNode(Head *L, Node *p) {
    Node *pre;

    if (L -> head == NULL) {
        return;
    }

    if (L -> head -> link == NULL) {
        free(L -> head);
        L -> head = NULL;
        return;
    } else if (p == NULL) {
        return;
    } else {
        pre = L -> head;
        while (pre -> link != p) {
            pre = pre -> link;
        }
        pre -> link = p -> link;
        free(p);
    }
}

// 리스트에서 x 노드 탐색
Node* searchNode(Head *L, char *x) {
    Node *temp;
    
    temp = L -> head;
    while (temp != NULL) {
        if (strcmp(temp -> data, x) == 0) {
            return temp;
        } else {
            temp = temp -> link;
        }
    }

    return temp;
}

// 리스트 노드 순서 역순
void reverse(Head *L) {
    Node *p, *q, *r;

    p = L -> head;
    q = NULL;
    r = NULL;

    while (p != NULL) {
        r = q;
        q = p;
        p = q -> link;
        q -> link = r;
    }

    L -> head = q;
}
