#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/resource.h>

int main() {
    int* ptr;
    struct rusage u; 
    for (int i = 0; i < 10; i++) {
        ptr = (int*)malloc(10*1024*1024);
        memset(ptr, 0, 10*1024*1024);
        getrusage(RUSAGE_SELF, &u);
        printf("Integral shared memory: %ld\n", u.ru_maxrss);
        sleep(1);
    }
    return 0;
}