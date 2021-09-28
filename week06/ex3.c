#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct {
    int at;
    int bt;
    int num;
    int wt;
    int tat;
    int ct;
} process;

void input(process *array, int n) {
    for (int i = 0; i < n; i++) {
        array[i].num = i + 1;
        printf("Enter arrival time and burst time\n");
        scanf("%d %d", &array[i].at, &array[i].bt);
    }
}

void output(process *array, int n) {
    printf("Answer\n");
    int avg_tat = 0;
    int avg_wt = 0;
    for (int i = 0; i < n; i++) {
        avg_tat += array[i].tat;
        avg_wt += array[i].wt;
        printf("Process %d:\n", array[i].num);
        printf("Wait time is %d Turnaround time is %d Completion time is %d\n", array[i].wt, array[i].tat, array[i].ct);
    }
    printf("Average turnaround time is %f Average wait time is %f", (double)avg_tat / (double)n, (double)avg_wt / (double)n);
}

void print_array(process *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", array[i].num);
        printf("Arrival time is %d Burst time is %d\n", array[i].at, array[i].bt);
    }
}

void swap(process *a, process *b) {
    process temp = *a;
    *a = *b;
    *b = temp;
}

int at_comparison(process a, process b) {
    if (a.at > b.at)
        return TRUE;
    return FALSE;
}

void sort(process *array, int n, int (*func)(process, process)) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (func(array[i], array[j]))
                swap(&array[i], &array[j]);
        }
    }
}

void turnaround_time(process *array, int n) {
    for (int i = 0; i < n; i++)
        array[i].tat = array[i].bt + array[i].wt;
}

void completion_time(process *array, int n) {
    for (int i = 0; i < n; i++)
        array[i].ct = array[i].tat + array[i].at;
}

int f(int burst, int quantum) {
    if (burst > quantum)
        return quantum;
    return burst;
}

void round_robin_wait(process *array, int n, int quantum) {
    for (int i = 0; i < n; i++) {
        int *remain = calloc(n, sizeof(int));
        for (int j = 0; j < n; j++)
            remain[j] = array[j].bt;
        int count = array[i].bt / quantum;
        float t = (float)array[i].bt / (float)quantum;
        if ((float)count == t)
            count -= 1;
        int total_sum = 0;
        for (int j = 0; j < count; j++) {
            for (int k = 0; k < n; k++) {
                if (total_sum >= array[k].at) {
                    int temp = f(remain[k], quantum);
                    total_sum += temp;
                    remain[k] -= temp;
                }
            }
        }
        for (int j = 0; j <= i; j++) {
            int temp = f(remain[j], quantum);
            total_sum += temp;
            remain[j] -= temp;
        }
        array[i].wt = total_sum - array[i].bt - array[i].at;
    }
}

int main() {
    printf("Enter number of processes and quantum\n");
    int n, quantum;
    scanf("%d %d", &n, &quantum);
    process *processes = (process*) calloc(n, sizeof(process));

    input(processes, n);

    printf("Got\n");
    print_array(processes, n);
    printf("\n");

    sort(processes, n, at_comparison);

    printf("Sorted\n");
    print_array(processes, n);
    printf("\n");

    round_robin_wait(processes, n, quantum);
    turnaround_time(processes, n);
    completion_time(processes, n);

    output(processes, n);
    exit(EXIT_SUCCESS);
}