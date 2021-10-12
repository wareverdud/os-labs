#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/resource.h>

int main() {
    int* ptr;
    for (int i = 0; i < 10; i++) {
        ptr = (int*)malloc(10*1024*1024);
        memset(ptr, 0, 10*1024*1024);
        sleep(1);
    }
    return 0;
}