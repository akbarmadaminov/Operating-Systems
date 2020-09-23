#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

typedef struct process {
    int at, bt, tat, ct, wt;
} process;

int n; /// number of processes

int min_ea(process p[]) {                       /// Returns non completed process with minimal arrival time
    int id = -1;
    for (int i = 0; i < n; i++) {
        if (p[i].ct != -1) continue;        /// If process is completed
        if (id == -1 || p[i].at < p[id].at)
            id = i;
    }
    return id;
}

int shortest(process p[], int cur) {            /// Returns non completed ready/waiting process with minimal burst time
    int id = -1;
    for (int i = 0; i < n; i++) {
        if (p[i].at > cur || p[i].ct != -1) continue;   /// If process is completed or not arrived yet

        if (id == -1 || p[i].bt < p[id].bt)
            id = i;
    }
    return id;
}

void SJF(process p[]) {
    int cur = 0, comp = 0;    /// Current time, number of completed processes
    while (comp < n) {
        int min = min_ea(p);                    /// the earliest time when non completed process arrives for now,
        if (cur < p[min].at) cur = p[min].at;   /// to exclude period where is no any ready/waiting processes

        int next = shortest(p, cur); /// Finds waiting process with the shortest burst time

        cur += p[next].bt;
        /// Process execution starts at cur. As algo is non-preemptive, it will be completed after p[next].burst_time.
        p[next].ct = cur;
        p[next].tat = p[next].ct - p[next].at;
        p[next].wt = p[next].tat - p[next].bt;
        comp++;
    }
}

int main() {
    scanf("%d", &n);
    process p[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].ct = -1; /// It means that process is not completed
    }

    SJF(p); /// Scheduler uses Shortest Job First algorithm for execution of processes

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
