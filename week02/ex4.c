#include <stdio.h>

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main() {
    int first, second;
    scanf("%d %d", &first, &second);
    swap(&first, &second);
    printf("%d %d", first, second);
    return 0;
}