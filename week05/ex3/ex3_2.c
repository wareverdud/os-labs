#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define TRUE 1
#define FALSE 0

int buffer = 0;

void* produce(void* args) {
    while (TRUE) {
        buffer += 1;
        usleep(100000);
    }
}

void* consume(void* args) {
    while (TRUE) {
        printf("%d\n", buffer);
        sleep(60);
    }
}

int main() {
    pthread_t consume_thread, produce_thread;
    pthread_create(&produce_thread, NULL, &produce, NULL);
    pthread_create(&consume_thread, NULL, &consume, NULL);
    sleep(61);
    exit(EXIT_SUCCESS);
}