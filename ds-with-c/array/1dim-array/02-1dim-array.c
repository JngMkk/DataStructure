#include <stdio.h>

int main() {
    short n, i;
    short multiply[9];

    printf("1~9의 정수를 입력하세요: ");

    while (1) {
        scanf("%d", &n);
        if (n < 0 || n > 9)
            printf("1~9의 정수를 입력하세요: ");
        else
            break;
    }

    printf("\n");
    for (i=1; i<10; i++) {
        multiply[i-1] = n * i;
        printf("%d * %d = %d\n", n, i, multiply[i-1]);
    }

    return 0;
}

/*
1~9의 정수를 입력하세요: 3   

3 * 1 = 3
3 * 2 = 6
3 * 3 = 9
3 * 4 = 12
3 * 5 = 15
3 * 6 = 18
3 * 7 = 21
3 * 8 = 24
3 * 9 = 27
*/
