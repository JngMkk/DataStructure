#include <stdio.h>
#define MAX 30

const int size = 8;
int sorted[MAX];

void merge(int a[], int start, int middle, int end) {
    int i, j, k, t;
    i = start;          // 첫 번째 부분집합의 시작 위치
    j = middle + 1;     // 두 번째 부분집합의 시작 위치
    k = start;          // 정렬된 집합을 저장할 배열의 시작 위치

    while (i <= middle && j <= end) {
        if (a[i] <= a[j]) {
            sorted[k++] = a[i++];
        } else {
            sorted[k++] = a[j++];
        }
    }

    if (i > middle) {
        for (t = j; t <= end; t++, k++) {
            sorted[k] = a[t];
        }
    } else {
        for (t = i; t <= middle; t++, k++) {
            sorted[k] = a[t];
        }
    }

    for (t = start; t <= end; t++) {
        a[t] = sorted[t];
    }

    for (t = 0; t < size; t++) {
        printf("%d ", a[t]);
    }
    printf("\n");
}

void mergeSort(int a[], int start, int end) {
    int middle;
    if (start < end) {
        middle = (start + end) / 2;
        mergeSort(a, start, middle);
        mergeSort(a, middle + 1, end);
        merge(a, start, middle, end);
    }
}

int main(void) {
    int i, arr[size] = {69, 10, 30, 2, 16, 8, 31, 22};

    mergeSort(arr, 0, size-1);
    
    return 0;
}