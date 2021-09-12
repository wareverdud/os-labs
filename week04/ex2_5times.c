#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    for (int i = 0; i < 5; i++) {
        fork();
        sleep(5);
    }
    return 0;
}

/* Overall 5 new processes will be launched
*  from initial ex2_5times
*/