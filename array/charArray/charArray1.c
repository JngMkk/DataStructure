#include <stdio.h>

int main() {
    char str[20] = "Data Structure!";
    short i;

    printf("str[]: ");
    for (i=0; str[i]; i++) {
        printf("%c", str[i]);
    }

    return 0;
}

// str[]: Data Structure!
