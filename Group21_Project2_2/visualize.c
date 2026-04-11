#include <stdio.h>
#include "scheduler.h"

void print_gantt_chart(int timeline[], int size) {
    printf("\nGantt Chart:\n|");
    for(int i = 0; i < size; i++) {
        printf(" P%d |", timeline[i]);
    }
    printf("\n");
}

void print_table(Process p[], int n) {
    printf("\n+------+---------+-------+----------+------------+----------+---------+\n");
    printf("| PID  | Arrival | Burst | Deadline | Completion | Turnaround| Waiting |\n");
    printf("+------+---------+-------+----------+------------+----------+---------+\n");
    for (int i = 0; i < n; i++) {
        printf("| P%-3d | %7d | %5d | %8d | %10d | %8d  | %7d |\n",
               p[i].pid, p[i].arrival, p[i].burst, p[i].deadline,
               p[i].completion, p[i].turnaround, p[i].waiting);
    }
    printf("+------+---------+-------+----------+------------+----------+---------+\n");

    float avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < n; i++) {
        avg_tat += p[i].turnaround;
        avg_wt += p[i].waiting;
    }
    printf("\nAvg Turnaround Time: %.2f\n", avg_tat / n);
    printf("Avg Waiting Time:    %.2f\n", avg_wt / n);
}

void log_execution(int pid, int time) {
    printf("Time %d: Process P%d running\n", time, pid);
}
