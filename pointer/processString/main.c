#include <stdio.h>

int main() {
    int i;
    char str1[20] = "Dreams come true!", str2[20], *p1, *p2;

    p1 = str1;  // 문자열 시작 주소를 p1에 지정
    printf("str1의 주소: %p, p1의 값: %p\n", str1, p1);
    printf("str1: %s, p1: %s\n", str1, p1);
    printf("%s\n", p1 + 7);

    p2 = &str1[7];
    printf("%s\n", p2);

    printf("\n");
    for (i = 16; i >= 0; i--) {
        putchar(*(p1 + i));
    }

    for (i = 0; i < 20; i++) {
        str2[i] = *(p1 + i);
    }

    printf("\n\nstr1: %s, str2: %s\n", str1, str2);

    *p1 = 'P';
    *(p1 + 1) = 'e';
    *(p1 + 2) = 'a';
    *(p1 + 3) = 'c';
    *(p1 + 4) = 'e';
    printf("\nstr1: %s\n", str1);

    return 0;
}

/*
str1의 주소: 0x16f486ad0, p1의 값: 0x16f486ad0
str1: Dreams come true!, p1: Dreams come true!
come true!
come true!

!eurt emoc smaerD

str1: Dreams come true!, str2: Dreams come true!

str1: Peaces come true!
*/
