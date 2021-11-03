#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

int main() {
    int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    if (fd == -1) return 0;
    struct input_event evt;
    char* t[] = {"RELEASED", "PRESSED"};
    while (1) {
        read(fd, &evt, sizeof(evt));
        if (evt.type == EV_KEY)
            if (evt.value <= 1)
                printf("%s, decimal %d, hex %x\n", t[evt.value], evt.code, evt.code);
    }
    return 0;
}