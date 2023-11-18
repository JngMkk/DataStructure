#include <stdio.h>

int main() {
    int sale[4] = { 157, 209, 251, 312 };

    for (int i = 0; i < 4; i++) {
        printf("addr of sale[%d]: %p, sale[%d] = %d\n", i, &sale[i], i, sale[i]);
    }

    return 0;
}

/*
addr of sale[0]: 0x16dcb6a80, sale[0] = 157
addr of sale[1]: 0x16dcb6a84, sale[1] = 209
addr of sale[2]: 0x16dcb6a88, sale[2] = 251
addr of sale[3]: 0x16dcb6a8c, sale[3] = 312
*/
