#include <stdio.h>

#include "arrayStack.h"

int top = -1;

// 스택이 공백인지
int isEmpty(void) {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

// 스택이 가득 찼는지
int isFull(void) {
    if (top == MAXSIZE -1) {
        return 1;
    } else {
        return 0;
    }
}

// 스택에 삽입
void push(elem item) {
    if (isFull()) {
        printf("Stack is Full.\n");
        return;
    } else {
        stack[++top] = item;    // top을 증가시킨 후 현재 top에 원소 삽입
    }
}

// 스택에서 마지막 원소 삭제 및 반환
elem pop(void) {
    if (isEmpty()) {
        printf("Stack is Empty.\n");
        return 0;
    } else {
        return stack[top--];    // 원소를 추출한 뒤 top 감소
    }
}

// 스택의 마지막 원소 반환
elem peek(void) {
    if (isEmpty()) {
        printf("Stack is Empty.\n");
        return 0;
    } else {
        return stack[top];
    }
}

// 스택의 모든 원소 출력
void printAll(void) {
    printf("Stack [ ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("]\n");
}
