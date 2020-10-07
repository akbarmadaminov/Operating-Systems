#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int ten_mb = 10*1024*1024;

int main() {
    for (int i = 0; i < 10; i++) {
        void *a = malloc(ten_mb);           /// Allocates 10 mb memory
        memset(a, 0, ten_mb);               /// Fills with 0
        sleep(1);                           /// Sleeps for 1 second
    }
}

/**
'vmstat' output during the program was running + some interval:

procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 0  0      0 3015672  10192  96124    0    0     7    67    2    8  0  0 100  0  0
 0  0      0 3005180  10192  96124    0    0     0     0    5   28  0  0 100  0  0
 0  0      0 2994972  10192  96124    0    0     0     0    7   35  0  0 100  0  0
 0  0      0 2984764  10192  96124    0    0     0     0    4   29  0  0 100  0  0
 0  0      0 2974304  10200  96116    0    0     0    12    6   40  0  0 98  2  0
 0  0      0 2964096  10200  96116    0    0     0     0    4   26  0  0 100  0  0
 0  0      0 2953888  10200  96116    0    0     0  2048    5   31  0  0 100  0  0
 0  0      0 2943428  10200  96116    0    0     0     0    7   33  0  0 100  0  0
 0  0      0 2933220  10200  96116    0    0     0     0    5   28  0  0 100  0  0
 0  0      0 2923012  10200  96116    0    0     0     0    4   26  0  0 100  0  0
 0  0      0 3024588  10200  96096    0    0     0     0   12   59  0  1 99  0  0
 0  0      0 3024596  10200  96096    0    0     0     0    4   24  0  0 100  0  0
 0  0      0 3024596  10208  96088    0    0     0    12    7   37  0  0 97  3  0

    procs section: There is no processes waiting to the access or in a 'sleep' state
    memory section: Amount of unallocated memory is decreasing (free column)
    swap section: As 'si' and 'so' was 0 in this period ->
        -> No amount of memory has been moved from swap to "real" memory (si column)
        -> No amount of memory has been moved from "real" memory to swap (so column)


Top output about ex2 at 3 different time:
PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
207 lnovak    20   0   43468  42000   1092 S   0.7   1.3   0:00.02 ex2              /// CPU - 0.7%; MEM - 1.3%
207 lnovak    20   0   74200  72812   1036 S   1.3   2.3   0:00.05 ex2              /// CPU - 1.3%  MEM - 2.3%
207 lnovak    20   0  104932 103472   1104 S   0.7   3.2   0:00.06 ex2              /// CPU - 0.7%  MEM - 3.2%

And program stops to use CPU or RAM after the execution finished                    /// CPU - 0.0%  MEM - 0.0%
**/
