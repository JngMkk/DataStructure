#pragma once

// 원형 연결 리스트의 노드 구조
typedef struct ListNode {
    char data[4];
    struct ListNode *link;
} Node;

// head 노드
typedef struct {
    Node *head;
} Head;

Head* initHead(void);
void printList(Head *CL);
void insertFront(Head *CL, char *x);
void insertMiddle(Head *CL, Node *pre, char *x);
void deleteNode(Head *CL, Node *old);
Node* searchNode(Head *CL, char *x);
