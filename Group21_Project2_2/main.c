#include <stdio.h>
#include "scheduler.h"

int main() {
    Process p[MAX];
    int n, choice;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("P%d Arrival Time: ", i+1);
        scanf("%d", &p[i].arrival);

        printf("P%d Burst Time: ", i+1);
        scanf("%d", &p[i].burst);

        printf("P%d Deadline: ", i+1);
        scanf("%d", &p[i].deadline);

        printf("P%d Tickets: ", i+1);
        scanf("%d", &p[i].tickets);

        p[i].pid = i + 1;
        p[i].remaining = p[i].burst;
        p[i].started = 0;
    }

    printf("\nChoose Algorithm:\n1. MLFQ\n2. Lottery\n3. EDF\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: mlfq(p, n); break;
        case 2: lottery(p, n); break;
        case 3: edf(p, n); break;
        default: printf("Invalid choice\n");
    }

    calculate_metrics(p, n);
    print_table(p, n);

    return 0;
}
