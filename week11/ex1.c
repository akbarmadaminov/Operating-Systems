#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>

int main() {
    char *nice = "This is a nice day";

    int fd = open("ex1.txt", O_RDWR);
    size_t sz = strlen(nice) + 1;

    char *mma = mmap(NULL, sz, PROT_WRITE, MAP_SHARED, fd, 0);

    strncpy(mma, nice, sz);         /// Write 'nice' on file
    ftruncate(fd, strlen(nice)); /// Resizes according to the nice string
    munmap(mma, sz);
    close(fd);
}

