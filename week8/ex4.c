#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int ten_mb = 10*1024*1024;

int main() {
    for (int i = 0; i < 10; i++) {
        void *a = malloc(ten_mb);               /// Allocates 10 mb memory
        memset(a, 0, ten_mb);                   /// Fills with 0

        struct rusage MU;
        getrusage(RUSAGE_SELF, &MU);
		printf("musage: %ld\n", MU.ru_maxrss);  /// Prints memory usage

        sleep(1);                               /// Sleeps for 1 second
    }
}
