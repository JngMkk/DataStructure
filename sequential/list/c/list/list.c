#include "list.h"

int insertElem(int L[], int n, int x) {
    int i, k = 0, move = 0; // move: 자리 이동 횟수 카운터

    // 삽입 위치 찾기
    for (i = 0; i < n; i++) {
        if (L[i] <= x && x <= L[i+1]) {
            k = i + 1;
            break;
        }
    }
    if (i == n) {   // 삽입 원소가 가장 큰 원소일 경우
        k = n;
    }

    // 마지막 원소부터 (삽입 위치+1)까지 뒤로 자리 이동
    for (i = n; i > k; i--) {
        L[i] = L[i - 1];
        move++;
    }

    L[k] = x;
    return move;
}

int removeElem(int L[], int n, int x) {
    int i, k = n, move = 0;

    // 삭제 위치 찾기
    for (i = 0; i < n; i++) {
        if (L[i] == x) {
            k = i;
            break;
        }
    }
    if (i == n) {
        move = n;
    }

    // (삭제 위치+1)부터 마지막 원소까지 앞으로 자리 이동
    for (i = k; i < n - 1; i++) {
        L[i] = L[i + 1];
        move++;
    }

    return move;
}
