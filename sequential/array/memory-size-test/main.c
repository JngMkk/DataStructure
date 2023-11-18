#include <stdio.h>

int main() {
    char c, c_array[100];
    int i, i_array[100];
    short s, s_array[100];
    float f, f_array[100];
    long l, l_array[100];

    printf("c = %d\tc_array = %d\n", sizeof(c), sizeof(c_array));
    printf("i = %d\ti_array = %d\n", sizeof(i), sizeof(i_array));
    printf("s = %d\ts_array = %d\n", sizeof(s), sizeof(s_array));
    printf("f = %d\tf_array = %d\n", sizeof(f), sizeof(f_array));
    printf("l = %d\tl_array = %d\n", sizeof(l), sizeof(l_array));

    return 0;
}

/*
c = 1   c_array = 100   char: 1byte
i = 4   i_array = 400   int: 4byte
s = 2   s_array = 200   short: 2byte
f = 4   f_array = 400   float: 4byte
l = 8   l_array = 800   long: 8byte
*/
