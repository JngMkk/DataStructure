#include <stdio.h>

int main() {
    char *pArray[2] = {"Korea", "Seoul"};
    char **pp;
    int i;

    pp = pArray; // 배열의 시작 주소. 즉 포인터 배열 pArray[0]의 주소
    printf(
        "pArray[0]의 주소: %p, pArray[0]의 값: %p, pArray[0]의 참조 문자열: %s, pArray[0]의 참조값: %c\n",
        &pArray[0], pArray[0], pArray[0], *pArray[0]
    );

    printf(
        "pArray[1]의 주소: %p, pArray[1]의 값: %p, pArray[1]의 참조 문자열: %s, pArray[1]의 참조값: %c\n",
        &pArray[1], pArray[1], pArray[1], *pArray[1]
    );

    printf(
        "pp의 주소: %p, pp의 값: %p, pp의 1차 참조값: %p, pp의 1차 참조 문자열: %s, pp의 2차 참조값: %c\n",
        &pp, pp, *pp, *pp, **pp
    );

    printf("\npArray[0]: ");
    for (i = 0; i < 5; i++) {
        printf("%c", *(pArray[0] + i));
    }
    printf("\n**pp: ");
    for (i = 0; i < 5; i++) {
        printf("%c", *(*pp + i));
    }
    printf("\n");

    return 0;
}