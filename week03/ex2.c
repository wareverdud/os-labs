#include <stdio.h>
#define n 5

void swap(int *first, int *second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}

void bubble_sort(int a[]) {
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n - i; j++) {
			if (a[j-1] > a[j]) {
				swap(a[j-i], a[j]);
			}
		}
	}
}

void show(int a[]) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	int a[n];
	printf("Enter 5 numbers\n");
	for (int i = 0; i < n; i++) {
		if (i != n-1) {
			scanf("%d ", &a[i]);
		} else {
			scanf("%d", &a[i]);
		}
	}
	bubble_sort(a);
	show(a);
	return 0;
}
