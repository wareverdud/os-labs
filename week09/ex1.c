#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0

int equal_age(int *ages, int n) {
    for (int i = 0; i < n; i++) {
        if (ages[i] != 0) {
            return FALSE;
        }
    }
    return TRUE;
}

int young_page(int *ages, int n, int *lru, int *frames) {
    int min_age = INT_MAX;
    int min_index = 0;

    if (equal_age(ages, n)) {
        for (int x = 0; x < n; x++) {
            if (frames[x] == lru[0]) {
                return x;
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (ages[i] < min_age) {
                min_age = ages[i];
                min_index = i;
            }
        }
        return min_index;
    }
}

void print(int *array, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int *frames = calloc(n, sizeof(int));
    int *ages = calloc(n, sizeof(int));
    int *b = calloc(m, sizeof(int));
    int *rb = calloc(n, sizeof(int));
    int *times = calloc(m, sizeof(m));
    int *a = calloc(m, sizeof(int));

    int *lru = calloc(n, sizeof(int));
    int lru_i = 0;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &times[i], &a[i]);
    }

    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            if (frames[k] == a[i]) {
                b[i] = 1;
                rb[k] = 1;

                if (lru_i != n) {
                    lru[lru_i] = a[i];
                    lru_i++;
                }
                else {
                    for (int x = 0; x < n - 1; x++) {
                        lru[x] = lru[x+1];
                    }
                    lru_i--;
                }

                break;
            }
        }
        if (b[i] == 0) {
            int full = TRUE;
            for (int k = 0; k < n; k++) {
                if (frames[k] == 0) {
                    frames[k] = a[i];
                    ages[k] = 0;
                    rb[k] = 1;

                    if (lru_i != n) {
                        lru[lru_i] = a[i];
                        lru_i++;
                    }
                    else {
                        for (int x = 0; x < n - 1; x++) {
                            lru[x] = lru[x+1];
                        }
                        lru_i--;
                    }

                    full = FALSE;
                    break;
                }
            }
            if (full) {
                int k = young_page(ages, n, lru, frames);
                frames[k] = a[i];
                ages[k] = 0;
                rb[k] = 1;

                if (lru_i != n) {
                    lru[lru_i] = a[i];
                    lru_i++;
                }
                else {
                    for (int x = 0; x < n - 1; x++) {
                        lru[x] = lru[x+1];
                    }
                    lru_i--;
                }

            }
        }
        if (i != m-1 && times[i] == times[i+1]) {
            continue;
        }
        else {
            for (int k = 0; k < n; k++) {
                ages[k] = ages[k] >> 1 | rb[k] << 7;
                rb[k] = 0;
                lru[k] = 0;
            }
            lru_i = 0;
        }
    }

    double r;
    int sum_of_b = 0;
    for (int i = 0; i < m; i++) {
        sum_of_b += b[i];
        printf("%d\n", b[i]);
    }
    r = (double)sum_of_b / (double)(m - sum_of_b);
    printf("%lf", r);
    return 0;
}