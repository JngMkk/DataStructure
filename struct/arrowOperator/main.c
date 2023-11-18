#include <stdio.h>
#include <string.h>

struct employee {
    char name[10];
    int year;
    int pay;
};

int main() {
    struct employee Lee;
    struct employee *LeePtr = &Lee;

    strcpy(LeePtr->name, "이수현");
    LeePtr->year = 2013;
    LeePtr->pay = 12500;
    printf("이름: %s, 입사: %d, 연봉: %d\n", LeePtr->name, LeePtr->year, LeePtr->pay);

    // 점 연산자(.)가 참조 연산자(*)보다 연산 우선수위가 높으므로 괄호를 넣어야 함.
    strcpy((*LeePtr).name, "이찬혁");
    (*LeePtr).year = 2013;
    (*LeePtr).pay = 10000;
    printf("이름: %s, 입사: %d, 연봉: %d\n", LeePtr->name, LeePtr->year, LeePtr->pay);

    return 0;
}

/*
이름: 이수현, 입사: 2013, 연봉: 12500
이름: 이찬혁, 입사: 2013, 연봉: 10000
*/
