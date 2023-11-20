#pragma once

typedef struct ListNode {
    struct ListNode *lLink;
    char data[4];
    struct ListNode *rLink;
} Node;

typedef struct {
    Node *head;
} Head;

Head* initHead(void);
void printList(Head *DL);
void insertNode(Head *DL, Node *pre, char *x);
void deleteNode(Head *DL, Node *old);
Node* searchNode(Head *DL, char *x);
