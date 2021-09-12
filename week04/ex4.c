#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define len 255

int main() {
    char cmd[len];
    char *argv[4];
    argv[0] = "/bin/sh";
    argv[1] = "-c";
    argv[3] = NULL;
    int status;
    while (1) {
        fgets(cmd, len, stdin);
        int x = fork();
        if (x == 0) {
            argv[2] = cmd;
            execvp(argv[0], argv);
        }
        else {
            wait(&status);
        }
    }
    return 0;
}