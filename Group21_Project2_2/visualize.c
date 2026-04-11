#include <stdio.h>
#include "scheduler.h"

void print_gantt_chart(int timeline[], int size) {
    printf("\nGantt Chart:\n|");
    for(int i = 0; i < size; i++) {
        printf(" P%d |", timeline[i]);
    }
    printf("\n");
}

void log_execution(int pid, int time) {
    printf("Time %d: Process P%d running\n", time, pid);
}
