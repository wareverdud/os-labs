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

int bt_comparison(process a, process b) {
    if (a.bt > b.bt)
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

void wait(process *array, int n) {
    for (int i = 0; i < n; i++)
        array[i].wt = array[i].tat - array[i].bt;
}

void turnaround_time(process *array, int n) {
    for (int i = 0; i < n; i++)
        array[i].tat = array[i].ct - array[i].at;
}

void pop(process *q, int n) {
    for (int i = 1; i < n; i++) {
        q[i-1] = q[i];
    }
}

void completion_time(process *array, int n) {
    process *copy = (process*) calloc(n, sizeof(process));
    for (int i = 0; i < n; i++) {
        copy[i].at = array[i].at;
        copy[i].bt = array[i].bt;
        copy[i].num = array[i].num;
    }
    process *q = (process*) calloc(n, sizeof(process));
    int elem_queue = 0;
    int time = 0;
    int processing = FALSE;
    int number_of_processed = 0;
    int check = TRUE;
    while (number_of_processed < n) {
        if (check) {
            for (int i = 0; i < n; i++) {
                if (copy[i].at == time) {
                    q[elem_queue] = copy[i];
                    elem_queue++;
                }
            }
        }
        if (!processing) {
            sort(q, elem_queue, bt_comparison);
        }
        if (q[0].bt != 0) {
            processing = TRUE;
            q[0].bt--;
            time++;
            check = TRUE;
        }
        else {
            for (int i = 0; i < n; i++) {
                if (array[i].num == q[0].num) {
                    array[i].ct = time;
                    break;
                }
            }
            pop(q, elem_queue);
            elem_queue--;
            processing = FALSE;
            number_of_processed++;
            check = FALSE;
        }
    }
}

int main() {
    printf("Enter number of processes and quantum\n");
    int n;
    scanf("%d", &n);
    process *processes = (process*) calloc(n, sizeof(process));

    input(processes, n);

    printf("Got\n");
    print_array(processes, n);
    printf("\n");

    sort(processes, n, at_comparison);

    printf("Sorted\n");
    print_array(processes, n);
    printf("\n");

    completion_time(processes, n);
    turnaround_time(processes, n);
    wait(processes, n);

    output(processes, n);
    exit(EXIT_SUCCESS);
}