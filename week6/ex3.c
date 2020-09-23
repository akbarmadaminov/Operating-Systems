#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

typedef struct process {
    int at, bt, tat, ct, wt, rt;
} process;

int n; /// number of processes
int q; /// quantum

void RR(process p[]) {
    int cur = 0, comp = 0;    /// Current time, number of completed processes
    while (comp < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].ct != -1) continue;        /// If process is completed

            if (cur < p[i].at) cur = p[i].at;

            /// This algo is pre-emptive, and we cannot allow process to run more than some q.
            /// And a process will be completed if a remaining time is <= q
            /// Otherwise it will be interrupted after q until the next turn and so on
            if (q >= p[i].rt) {
                cur += p[i].rt;
                p[i].ct = cur;
                p[i].tat = p[i].ct - p[i].at;
                p[i].wt = p[i].tat - p[i].bt;
                comp++;
            } else {
                p[i].rt -= q;
                cur += q;
            }
        }
    }
}

int main() {
    scanf("%d%d", &q, &n);
    process p[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].ct = -1; /// It means that process is not completed
        p[i].rt = p[i].bt;      /// Time needed to complete a process
    }

    RR(p); /// Scheduler uses Round-Robin algorithm for execution of processes

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
    printf("Average Turnaround time: %.2lf\nAverage Waiting time: %.2lf\n", avtat / n, avwt / n);
}
