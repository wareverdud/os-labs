#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
    int n = 7;
    pid_t x = fork();
    if (x < 0) {
        printf("Error with forking occured\n");
        return -1;
    }
    else if (x == 0) {
        printf("Hello from child [%d-%d]\n", getpid(), n);
    }
    else {
        printf("Hello from parent [%d-%d]\n", getpid(), n);
    }
    return 0;
}

/** First output might be either from child process or from
 *  parent process because they are running in quasi-parallel
 *  mode.
 */