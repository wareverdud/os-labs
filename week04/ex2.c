#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    for (int i = 0; i < 3; i++) {
        fork();
        sleep(5);
    }
    return 0;
}

/* Overall 3 new processes will be launched
*  from initial ex2
*/