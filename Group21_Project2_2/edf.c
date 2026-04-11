#include <stdio.h>
#include "scheduler.h"

void edf(Process p[], int n) {
    int time = 0, completed = 0;

    printf("\n[EDF Scheduling Running...]\n");

    while (completed < n) {

        // Find the ready process with the earliest deadline
        int idx = -1;
        int min_deadline = 99999;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].remaining > 0) {
                if (p[i].deadline < min_deadline) {
                    min_deadline = p[i].deadline;
                    idx = i;
                }
            }
        }

        // No process ready — advance time
        if (idx == -1) {
            time++;
            continue;
        }

        // Record response time on first run
        if (!p[idx].started) {
            p[idx].response = time - p[idx].arrival;
            p[idx].started = 1;
        }

        // Execute for 1 time unit (preemptive)
        p[idx].remaining--;
        time++;

        // Warn if deadline is missed
        if (p[idx].remaining == 0) {
            p[idx].completion = time;
            if (time > p[idx].deadline) {
                printf("  WARNING: P%d missed its deadline! (deadline=%d, completion=%d)\n",
                       p[idx].pid, p[idx].deadline, time);
            }
            completed++;
        }
    }
}