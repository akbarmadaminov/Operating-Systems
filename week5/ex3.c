#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

#define capacity 20

int a[capacity], cnt = 0;         /// Capacity of container, current number of **
int full = 0, empty = 1;    /// Initially container is empty


int cc = 0;

void *produce(void *x) {
    while(1) {
        if (full) continue;

        a[cnt] = rand() % 100;              /// Produce new ** if our container is not full
        printf("Hey, new product: %d\n", a[cnt]);
        cnt++;

        if (cnt == capacity) full = 1;
        empty = 0;
    }
    pthread_exit(0);
}

void *consume(void *x) {
	while(1) {
        if (empty) continue;

        printf("I bought this: %d\n", a[cnt]);          /// Consumer bought ** if there exist
        cnt--;

        if (cnt == 0) empty = 1;
        full = 0;
    }
    pthread_exit(0);
}

int main() {
    pthread_t prod, cons;

    /// Creates two thread to produce-consume
    pthread_create(&prod, NULL, produce, NULL);
	pthread_create(&cons, NULL, consume, NULL);

    /// Waits until all threads terminate
	pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    return 0;
}
/**
    As I didn't use synchronization primitives
    fatal race condition will occur.

    It can stop differently
    For example:
        -once race condition occured at about 6890 (I didn't print anything and print clock() once per 500 iterations)
        -once it occured at about 12234 (I printed clock() and produce/consume info once per 100 iterations)
**/
