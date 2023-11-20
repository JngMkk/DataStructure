#pragma once

typedef int elem;

typedef struct StackNode {
    elem data;
    struct StackNode *link;
} Node;

Node *top;

int isEmpty(void);
void push(elem item);
elem pop(void);
elem peek(void);
void printAll(void);
