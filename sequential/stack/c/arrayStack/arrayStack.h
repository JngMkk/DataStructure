#pragma once
#define MAXSIZE 100

typedef int elem;
elem stack[MAXSIZE];

int isEmpty(void);
int isFull(void);
void push(elem item);
elem pop(void);
elem peek(void);
void printAll(void);
