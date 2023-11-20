#include <stdio.h>
#include <string.h>

int main() {
    short i, len = 0;
    char str[50];

    printf("문자열을 입력하세요: ");
    gets(str);
    
    printf("\n입력된 문자열: \"");
    for (i=0; str[i]; i++) {
        printf("%c", str[i]);
        len += 1;
    }
    printf("\"\n");
    printf("길이 = %d\n", len);

    return 0;
}

/*
문자열을 입력하세요: HelloWorld!

입력된 문자열: "HelloWorld!"
길이 = 11
*/
