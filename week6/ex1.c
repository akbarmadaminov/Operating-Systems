#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

typedef struct process {
    int at, bt, tat, ct, wt;
} process;

int n; /// number of processes

void FCFS(process p[]) {
    int cur = 0;    /// Current time

    /// We execute in the given order
    for (int i = 0; i < n; i++) {
        if (cur < p[i].at) cur = p[i].at;
        cur += p[i].bt;
        /// Process execution starts at cur. As algo is non-preemptive, it will be completed after p[i].burst_time.
        p[i].ct = cur;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
}

int main() {
    scanf("%d", &n);
    process p[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p[i].at, &p[i].bt);
    }

    FCFS(p); /// Scheduler uses First come - First served algorithm for execution of processes

    /// Let's print metrics table after all processes completed

    puts("ID  CT  TAT  WT");
    for (int i = 0; i < n; i++) {
        printf("%-4d%-4d%-5d%-4d\n", i, p[i].ct, p[i].tat, p[i].wt);
    }


    /// Counts Average turnaround and waiting time
    double avtat = 0.0, avwt = 0.0;
    for (int i = 0; i < n; i++) {
        avtat += p[i].tat;
        avwt += p[i].wt;
    }
    printf("Average Turnaround time: %.4lf\nAverage Waiting time: %.4lf\n", avtat / n, avwt / n);
}
