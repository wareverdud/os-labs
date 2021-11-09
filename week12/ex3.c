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
    FILE* out = fopen("./ex3.txt", "w");
    struct input_event evt;
    char* t[] = {"RELEASED", "PRESSED"};

    int pe[] = {0, 0};
    int cap[] = {0, 0};
    int os[] = {0, 0};

    while (1) {
        read(fd, &evt, sizeof(evt));
        if (evt.type == EV_KEY) {
            if (evt.value == 1 && evt.code == 25)
                pe[0] = 1;
            if (evt.value == 1 && evt.code == 18)
                pe[1] = 1;
            if (evt.value == 0 & evt.code == 25)
                pe[0] = 0;
            if (evt.value == 0 && evt.code == 18)
                pe[1] = 0;
            if (evt.value == 1 && evt.code == 30)
                cap[1] = 1;
            if (evt.value == 0 && evt.code == 30)
                cap[1] = 0;
            if (evt.value == 1 && evt.code == 46)
                cap[0] = 1;
            if (evt.value == 0 && evt.code == 46)
                cap[0] = 0;
            if (pe[0] == 1 && cap[0] == 1 && cap[1] == 1) {
                printf("Get some capuccino!\n");
                fprintf(out, "Get some capuccino!\n");
            }
            if (pe[0] == 1 && pe[1] == 1) {
                printf("I passed the Exam!\n");
                fprintf(out, "I passed the Exam!\n");
            }
            if (evt.value == 0 && evt.code == 24)
                os[0] = 0;
            if (evt.value == 1 && evt.code == 24)
                os[0] = 1;
            if (evt.value == 0 && evt.code == 31)
                os[1] = 0;
            if (evt.value == 1 && evt.code == 31)
                os[1] = 1;
            if (os[0] == 1 && os[1] == 1) {
                printf("Operating Systems\n");
                fprintf(out, "Operating Systems\n");
            }
            fflush(out);
        }
    }
    fclose(out);
    return 0;
}