#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

void *func(void *id) {
    int *cur_id = (int *)id;
	printf("Print thread #%d\n", *cur_id);
}

int main() {
    int n = 5;
    pthread_t id[n];
    for (int i = 0; i < n; i++) {
        printf("Create thread #%d\n", i);
        pthread_create(id+i, NULL, func, &i);        /// function to create a thread
        pthread_join(id[i], NULL);                       /// Look at the end
	}
	return 0;
}
/**
    As we call function pthread_join(x, NULL) after creating a thread, it waits until the thread with id=x terminates.
    So execution order of threads is preserved.
    Output:
    Create thread #0
    Print thread #0
    Create thread #1
    Print thread #1
    Create thread #2
    Print thread #2
    Create thread #3
    Print thread #3
    Create thread #4
    Print thread #4
**/
