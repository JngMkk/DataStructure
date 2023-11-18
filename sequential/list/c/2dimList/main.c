#include <stdio.h>

/*
2차원 배열 구조를 논리적으로 표현할 때는 형과 열의 구조로 나타내지만, 실제로 메모리에는 1차원 구조로 저장됨.
2차원인 논리적 순서가 1차원인 물리적 순서로 변환되는 방법에는 행 우선 순서와 열 우선 순서가 있음.

행 우선 순서 방법은 행을 기준으로 같은 행 안에 있는 열을 먼저 저장함.
    - 배열 원소 위치 계산 방법 (행 개수 n, 열 개수 m, 시작 주소 a, 원소 길이 l)
        - A[i][j] = a + (i * m + j) * l

열 우선 순서 방법은 열을 기준으로 같은 열 안에 있는 행을 먼저 저장함.
    - 배열 원소 위치 계산 방법 (행 개수 n, 열 개수 m, 시작 주소 a, 원소 길이 l)
        - A[i][j] = a + (j * n + i) * l

C 컴파일러는 행 우선 순서 방법을 사용.
*/

int main(void) {
    int *p, n = 0;
    int sale[2][4] = {
        { 63, 84, 140, 130 },
        { 157, 209, 251, 312 }
    };

    p = &sale[0][0];
    for (int i = 0; i < 8; i++) {
        printf("addr of physical idx%d: %p, sale physical idx%d: %d\n", i, p, i, *p);
        p++;
    }

    return 0;
}

/*
addr of physical idx0: 0x16b276a60, sale physical idx0: 63
addr of physical idx1: 0x16b276a64, sale physical idx1: 84
addr of physical idx2: 0x16b276a68, sale physical idx2: 140
addr of physical idx3: 0x16b276a6c, sale physical idx3: 130
addr of physical idx4: 0x16b276a70, sale physical idx4: 157
addr of physical idx5: 0x16b276a74, sale physical idx5: 209
addr of physical idx6: 0x16b276a78, sale physical idx6: 251
addr of physical idx7: 0x16b276a7c, sale physical idx7: 312
*/
