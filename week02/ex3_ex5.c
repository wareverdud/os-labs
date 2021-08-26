#include <stdio.h>
#include <stdlib.h>

void right_triangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void ex3(int n) {
    int cur_row = 1;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n - cur_row; k++) {
            printf(" ");
        }
        for (int k = n - cur_row; k < n + cur_row - 1; k++) {
            printf("*");
        }
        for (int k = n + cur_row - 1; k < 2 * n - 1; k++) {
            printf(" ");
        }
        printf("\n");
        cur_row++;
    }
}

void triangle(int n) {
    int middle = n / 2 + 1;
    right_triangle(middle);
    for (int i = middle - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            printf("*");
        }
        printf("\n");
    }
}

void square(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int n;
    if (argc > 1) {
        sscanf(argv[1], "%d", &n);
    }
    ex3(n);
    printf("\n");
    right_triangle(n);
    printf("\n");
    triangle(n);
    printf("\n");
    square(n);
    return EXIT_SUCCESS;
}