#include <stdio.h>

int main() {
    short i;
    short score[3] = { 91, 86, 97 };
    char grade[3] = { 'A', 'B', 'A' };

    for (i=0; i<3; i++) {
        printf("%d학년: 총점 = %d, 등급 %c\n", i + 1, score[i], grade[i]);
    }

    return 0;
}

/*
1학년: 총점 = 91, 등급 A
2학년: 총점 = 86, 등급 B
3학년: 총점 = 97, 등급 A
*/
