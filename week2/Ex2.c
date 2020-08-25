#include <stdio.h>

int inf = 1e6;

int main() {
    char a[inf];
    scanf("%s", &a);
    int n = strlen(a);
    for (int i = n - 1; i >= 0; i--) {
        printf("%c", a[i]);
    }
    printf("\n");
}
