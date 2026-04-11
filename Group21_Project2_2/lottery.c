#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "scheduler.h"

void lottery(Process p[], int n) {
    int curr_time = 0, completed = 0;

    srand((unsigned int)time(NULL));

    printf("\n[Lottery Scheduling Running...]\n");

    while (completed < n) {


        int total_tickets = 0;
        for (int i = 0; i < n; i++) {
            if (p[i].remaining > 0 && p[i].arrival <= curr_time) {
                total_tickets += p[i].tickets;
            }
        }


        if (total_tickets == 0) {
            curr_time++;
            continue;
        }


        int winner = rand() % total_tickets;
        int sum = 0, idx = -1;

        for (int i = 0; i < n; i++) {
            if (p[i].remaining > 0 && p[i].arrival <= curr_time) {
                sum += p[i].tickets;
                if (sum > winner) {
                    idx = i;
                    break;
                }
            }
        }

        if (idx == -1) continue;


        if (!p[idx].started) {
            p[idx].response = curr_time - p[idx].arrival;
            p[idx].started = 1;
        }


        p[idx].remaining--;
        curr_time++;

        if (p[idx].remaining == 0) {
            p[idx].completion = curr_time;
            completed++;
        }
   }
}
