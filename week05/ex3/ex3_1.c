// Program can be exited only by Ctrl and C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define TRUE 1
#define FALSE 0

int position = 0;
int n;
int *buffer;

void print() {
	for (int i = 0; i < n; i++) {
			printf("%d ", buffer[i]);
		}
	printf("\n");
}

void* produce(void* args) {
    while (TRUE) {
		printf("Buffer before producing - ");
		print();
        if (position >= 0 && position < n) {
            int number = rand() % 20 + 1;
            printf("Produced %d\n", number);
            buffer[position] = number;
            position++;
        }
        else {
            
            printf("Buffer is full. Cannot produce more\n");
            sleep(70);
        }
		printf("Buffer after producing - ");
		print();
        sleep(60);
    }
}

void* consume(void* args) {
    while (TRUE) {
		printf("Buffer before consuming - ");
		print();
        if (position <= n && position > 0) {
            printf("Consumed %d\n", buffer[position-1]);
			buffer[position-1] = 0;
            position--;
        }
        else {
            printf("Buffer is empty. Cannot consume more\n");
            sleep(70);
        }
		printf("Buffer after consuming - ");
		print();
        sleep(60);
    }
}

int main() {
	srand(time(NULL));
    scanf("%d", &n);
    buffer = calloc(n, sizeof(buffer));
    pthread_t consume_thread, produce_thread, debug;
    pthread_create(&produce_thread, NULL, &produce, NULL);
    pthread_create(&consume_thread, NULL, &consume, NULL);
    pthread_join(consume_thread, NULL);
    pthread_join(produce_thread, NULL);
    exit(EXIT_SUCCESS);
}