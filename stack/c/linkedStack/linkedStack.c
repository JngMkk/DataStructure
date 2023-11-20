#include <stdio.h>
#include <stdlib.h>

#include "linkedStack.h"

// 스택이 공백인지
int isEmpty(void) {
    if (top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// 원소 삽입
void push(elem item) {
    Node *temp = (Node*)malloc(sizeof(Node));

    temp -> data = item;
    temp -> link = top;
    top = temp;
}

// 마지막 원소 삭제 및 반환
elem pop(void) {
    elem item;
    Node *temp = top;

    if (isEmpty()) {
        printf("Stack is Empty\n");
        return 0;
    } else {
        item = temp -> data;
        top = temp -> link;
        free(temp);
        return item;
    }
}

// 마지막 원소 검색
elem peek(void) {
    if (isEmpty()) {
        printf("Stack is Empty\n");
        return 0;
    } else {
        return (*top).data;
    }
}

void printAll(void) {
    Node *p = top;
    printf("Stack [ ");
    while (p) {
        printf("%d ", p -> data);
        p = p -> link;
    }
    printf("]\n");
}
