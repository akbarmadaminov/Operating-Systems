#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>

int main() {
    char buffer[100];
    setvbuf(stdout, buffer, _IOLBF, 100);   /// Line buffering

    char *out = "Hello";
    for (int i = 0; i < 5; i++) {
        printf("%c", out[i]);
        sleep(1);
    }

    fclose(stdout);
    return 0;
}
