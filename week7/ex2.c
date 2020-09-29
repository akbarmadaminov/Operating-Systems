#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

int n;

int main() {
    scanf("%d", &n);
    int *a = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
        a[i] = i;
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    puts("");
    free(a);
}
