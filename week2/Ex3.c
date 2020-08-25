#include <stdio.h>

void figure(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int j = 1; j < 2 * i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main(int args, char *arg[]) {
    int n;
    sscanf(arg[1], "%d", &n);
    figure(n);
}

