#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>

int main() {
    int fi = open("ex1.txt", O_RDWR);           /// Source file
    int fo = open("ex1.memcpy.txt", O_RDWR);     /// Destination file

    struct stat file;
    fstat(fi, &file);
    size_t sz = file.st_size;

    char *from = mmap(NULL, sz, PROT_READ, MAP_SHARED, fi, 0);
    char *to = mmap(NULL, sz, PROT_WRITE, MAP_SHARED, fo, 0);

    ftruncate(fo, sz);          /// Resize according to the source file
    strncpy(to, from, sz);      /// Copies from the source file to new

    munmap(from, sz);
    munmap(to, sz);

    close(fi);
    close(fo);
}

