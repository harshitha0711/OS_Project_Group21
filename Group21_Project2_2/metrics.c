//#include <stdio.h>
#include "scheduler.h"

void calculate_metrics(Process p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting    = p[i].turnaround - p[i].burst;
    }
}

void print_table(Process p[], int n) {
    printf("\n%-5s %-8s %-8s %-12s %-12s %-10s %-10s\n",
           "PID", "Arrival", "Burst", "Completion", "Turnaround", "Waiting", "Response");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-8d %-8d %-12d %-12d %-10d %-10d\n",
               p[i].pid, p[i].arrival, p[i].burst,
               p[i].completion, p[i].turnaround,
               p[i].waiting, p[i].response);
    }
}
//
