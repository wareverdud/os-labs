#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show(int* a, int n) {
    if (a == NULL) return;
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int* reallocating(int *ptr, int size, int newsize) {
    if (ptr == NULL) {
        ptr = malloc(newsize*sizeof(int));
        return ptr;
    }
    if (newsize == 0) {
        free(ptr);
        return NULL;
    }
    int* new = malloc(newsize*sizeof(int));
    if (newsize > size) {
        for (int i = 0; i < size; i++) {
            new[i] = ptr[i];
        }
        for (int i = size; i < newsize; i++) {
            new[i] = 0;
        }
    }
    else {
        for (int i = 0; i < newsize; i++) {
            new[i] = ptr[i];
        }
    }
    free(ptr);
    return new;
}

int main() {
    int old;
    printf("Enter old size:\n");
    scanf("%d", &old);
    int *a = malloc(sizeof(int) * old);
    for (int i = 0; i < old; i++) {
        a[i] = i;
    }
    show(a, old);
    int new;
    printf("Enter new size:\n");
    scanf("%d", &new);
    a = reallocating(a, old, new);
    show(a, new);
    return 0;
}
