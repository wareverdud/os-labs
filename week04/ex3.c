#include <stdio.h>
#include <stdlib.h>
#define len 255

int main() {
    while (1) {
        char cmd[len];
        fgets(cmd, len, stdin);
        system(cmd);
    }    
    return 0;
}