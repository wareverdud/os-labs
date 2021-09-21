#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    pthread_t thread_id;
    int thread_num;
    char *string;
} thread_info;

void* job(void* args) {
    thread_info *t = (thread_info*)args;
    // printf("Id - %ld ", t->thread_id);
    printf("Thread number %d started execution\n", t->thread_num);
    printf("%s %d\n", t->string, t->thread_num);
    printf("Thread number %d stopped execution\n", t->thread_num);
}

int main() {
    thread_info *tinfo;
    int n;
    scanf("%d", &n);
    tinfo = calloc(n, sizeof(thread_info));
    for (int i = 0; i < n; i++) {
        tinfo[i].string = "Hello from thread";
        tinfo[i].thread_num = i;
        pthread_create(&tinfo[i].thread_id, NULL, &job, (void*)&tinfo[i]);
        pthread_join(tinfo[i].thread_id, NULL);
    }
    exit(EXIT_SUCCESS);
}