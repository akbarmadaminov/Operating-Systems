#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define sz 20

int main() {
    char s[sz+1];
    FILE *fp = fopen("/dev/random", "r");

    fgets(s, sz+1, fp);
    FILE *out = fopen("ex1.txt", "w");

    fprintf(out, "%s", s);
    printf("%s", s);
    fclose(fp);
    fclose(out);
}

