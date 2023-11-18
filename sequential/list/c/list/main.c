#include <stdio.h>
#include "list.h"

int main(void) {
    int list[MAX] = { 10, 20, 40, 50, 60, 70 };
    int i, move, size = 6;

    printf("삽입 전 선형 리스트: ");
    for (i = 0; i < size; i++) {
        printf("%3d", list[i]);
    }

    move = insertElem(list, size, 30);
    ++size;
    printf("\n삽입 후 선형 리스트: ");
    for (i = 0; i < size; i++) {
        printf("%3d", list[i]);
    }
    printf("\n자리 이동 횟수: %d\n", move);

    move = removeElem(list, size, 30);
    if (move == size) {
        printf("해당 원소 없음.");
    } else {
        --size;
        printf("삭제 후 선형 리스트: ");
        for (i = 0; i < size; i++) {
            printf("%3d", list[i]);
        }
        printf("\n자리 이동 횟수: %d\n", move);
    }
}

/*
삽입 전 선형 리스트:  10 20 40 50 60 70
삽입 후 선형 리스트:  10 20 30 40 50 60 70
자리 이동 횟수: 4
삭제 후 선형 리스트:  10 20 40 50 60 70
자리 이동 횟수: 4
*/
