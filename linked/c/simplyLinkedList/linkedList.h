#pragma once

// 단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
    char data[4];
    struct ListNode *link;
} Node;

// 리스트 시작을 나타내는 노드를 구조체로 정의
typedef struct {
    Node *head;
} Head;

Head* initHead(void);
void freeMemory(Head *L);
void printList(Head *L);
void insertFront(Head *L, char *x);
void insertMiddle(Head *L, Node *pre, char *x);
void insertBack(Head *L, char *x);
void deleteNode(Head *L, Node *p);
Node* searchNode(Head *L, char *x);
void reverse(Head *L);
