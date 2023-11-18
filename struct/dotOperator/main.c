#include <stdio.h>

struct employee {
    char name[10];
    int year;
    int pay;
};

int main() {
    struct employee Lee[2] = {
        { "이수현", 2013, 12500 },
        { "이찬혁", 2013, 10000 }
    };

    for (int i = 0; i < 2; i++) {
        printf("이름: %s, 입사: %d, 연봉: %d\n", Lee[i].name, Lee[i].year, Lee[i].pay);
    }

    return 0;
}

/*
이름: 이수현, 입사: 2013, 연봉: 12500
이름: 이찬혁, 입사: 2013, 연봉: 10000
*/
