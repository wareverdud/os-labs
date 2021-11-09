#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

int main() {
    int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    FILE *out = fopen("./ex2.txt", "w");
    if (fd == -1) return 0;
    struct input_event evt;
    while (1) {
        read(fd, &evt, sizeof(evt));
        if (evt.type == EV_KEY)
            if (evt.value == 0) {
                printf("RELEASED, decimal %d, hex %x\n", evt.code, evt.code);
                fprintf(out, "RELEASED, decimal %d, hex %x\n", evt.code, evt.code);
            }
            else if (evt.value == 1) {
                printf("PRESSED, decimal %d, hex %x\n", evt.code, evt.code);
                fprintf(out, "PRESSED, decimal %d, hex %x\n", evt.code, evt.code);
            }
            fflush(out);
    }
    fclose(out);
    return 0;
}