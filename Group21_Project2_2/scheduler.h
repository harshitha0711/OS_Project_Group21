#ifndef SCHEDULER_H
#define SCHEDULER_H

#define MAX 100

typedef struct {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int waiting;
    int turnaround;
    int response;
    int deadline;
    int tickets;
    int started;
} Process;

// Algorithms
void mlfq(Process p[], int n);
void lottery(Process p[], int n);
void edf(Process p[], int n);

// Metrics
void calculate_metrics(Process p[], int n);

// Visualization
void print_gantt_chart(int timeline[], int size);
void print_table(Process p[], int n);
void log_execution(int pid, int time);

#endif
