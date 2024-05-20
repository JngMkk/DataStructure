#include <stdio.h>

int i = 0;

void quickSort(int a[], int begin, int end, int size) {
    if (begin >= end)
        return;
    
    int pivot, L, R, t, temp;

    L = begin;
    R = end;
    pivot = (begin + end) / 2;
    printf("[%d단계]: pivot = %d\n", ++i, a[pivot]);

    while (L < R) {
        while ((a[L] < a[pivot]) && (L < R)) L++;
        while ((a[R] >= a[pivot]) && (L < R)) R--;

        if (L < R) {
            temp = a[L];
            a[L] = a[R];
            a[R] = temp;
            if (L == pivot)
                pivot = R;
        }
    }
    temp = a[pivot];
    a[pivot] = a[R];
    a[R] = temp;
    for (t = 0; t < size; t++)
        printf("%d ", a[t]);
    printf("\n");

    quickSort(a, begin, R - 1, size);
    quickSort(a, R + 1, end, size);
}



int main(void) {
    int i, arr[8] = {69, 10, 30, 2, 16, 8, 31, 22};
    int size = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, size-1, size);
    
    return 0;
}

