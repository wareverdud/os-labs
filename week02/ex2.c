#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define len 50

int main() {
    char string[len];
    fgets(string, len, stdin);
    for (int i = strlen(string) - 1; i >= 0; --i) {
        printf("%c", string[i]);
    }
    return EXIT_SUCCESS;
}