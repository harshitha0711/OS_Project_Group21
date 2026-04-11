#include <stdio.h>
#include "scheduler.h"
void mlfq(Process p[], int n) {
    int time = 0, completed = 0;
    int q1[MAX], q2[MAX], q3[MAX];
    int f1 = 0, r1 = 0, f2 = 0, r2 = 0, f3 = 0, r3 = 0;
    int inqueue[MAX] = {0};
    printf("\n[MLFQ Scheduling Running...]\n");
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].remaining > 0 && !inqueue[i]) {
                q1[r1++] = i;
                inqueue[i] = 1;
            }
        }
        if (f1 < r1) {
            int idx = q1[f1++];
            int tq = 2;
            if (!p[idx].started) {
                p[idx].response = time - p[idx].arrival;
                p[idx].started = 1;
            }
            int run = (p[idx].remaining < tq) ? p[idx].remaining : tq;
            for (int t = 0; t < run; t++) {
                p[idx].remaining--;
                time++;
                for (int i = 0; i < n; i++) {
                    if (p[i].arrival <= time && p[i].remaining > 0 && !inqueue[i]) {
                        q1[r1++] = i;
                        inqueue[i] = 1;
                    }
                }
            }
            if (p[idx].remaining == 0) {
                p[idx].completion = time;
                completed++;
            } else {
                if (f1 < r1) {
                }
                q2[r2++] = idx;
            }

        } else if (f2 < r2) {
            int idx = q2[f2++];
            int tq = 4;
            if (!p[idx].started) {
                p[idx].response = time - p[idx].arrival;
                p[idx].started = 1;
            }
            int run = (p[idx].remaining < tq) ? p[idx].remaining : tq;
            for (int t = 0; t < run; t++) {
                p[idx].remaining--;
                time++;
                for (int i = 0; i < n; i++) {
                    if (p[i].arrival <= time && p[i].remaining > 0 && !inqueue[i]) {
                        q1[r1++] = i;
                        inqueue[i] = 1;
                    }
                }
                if (f1 < r1) {
                    break;
                }
            }
            if (p[idx].remaining == 0) {
                p[idx].completion = time;
                completed++;
            } else if (f1 < r1) {
                q2[--f2] = idx;
            } else {
                q3[r3++] = idx;
            }
        } else if (f3 < r3) {
            int idx = q3[f3++];

            if (!p[idx].started) {
                p[idx].response = time - p[idx].arrival;
                p[idx].started = 1;
            }
            while (p[idx].remaining > 0) {
                p[idx].remaining--;
                time++;
                for (int i = 0; i < n; i++) {
                    if (p[i].arrival <= time && p[i].remaining > 0 && !inqueue[i]) {
                        q1[r1++] = i;
                        inqueue[i] = 1;
                    }
                }
            }
            p[idx].completion = time;
            completed++;
        } else {
            time++;
        }
    }
}
