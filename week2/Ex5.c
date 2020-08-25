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

void figure_1(int n) {
    for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                printf("*");
            }
            printf("\n");
    }
    printf("\n");
}

void figure_2(int n) {
    for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
        for (int i = n / 2; i < n; i++) {
            for (int j = 1; j <= n - i; j++) {
                printf("*");
            }
            printf("\n");
    }
    printf("\n");
}

void figure_3(int n) {
    for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                printf("*");
            }
            printf("\n");
    }
    printf("\n");
}

int main(int args, char *arg[]) {
    int n;
    sscanf(arg[1], "%d", &n);
    puts("Right-Side-Up triangle:");
    figure(n);
    puts("Right triangle:");    figure_1(n);
    puts("Pyramid:");
    figure_2(n);
    puts("Shield:");
    figure_3(n);
}


