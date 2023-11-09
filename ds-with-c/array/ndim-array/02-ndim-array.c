#include <stdio.h>

int main() {
    short i, j, k;
    char student[2][3][20];

    for (i=0; i<2; i++) {
        printf("%d의 이름: ", i+1);
        gets(student[i][0]);
        printf("%d의 학과: ", i+1);
        gets(student[i][1]);
        printf("%d의 학번: ", i+1);
        gets(student[i][2]);
        printf("\n");
    }

    for (i=0; i<2; i++) {
        printf("\n학생 %d", i+1);
        for (j=0; j<3; j++) {
            printf("\n");
            for (k=0; student[i][j][k] != '\0'; k++) {
                printf("%c", student[i][j][k]);
            }
        }
    }
    
    return 0;
}

/*
1의 이름: ABC
1의 학과: CS
1의 학번: 1111

2의 이름: DEF
2의 학과: CS
2의 학번: 2222


학생 1
ABC
CS
1111
학생 2
DEF
CS
2222
*/