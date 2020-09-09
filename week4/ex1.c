#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int a = 1234;
    pid_t pid = fork();

    if (pid > 0) {
        printf("Hello from parent [%d - %d]\n", pid, a);
    } else if (pid == 0) {
        printf("Hello from child [%d - %d]\n", pid, a);
    } else {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
/**
    If fork() returns negative value - Creation of child process was unsuccessful
    Otherwise it creates a new (child) process, which works concurrently with the old (parent) process
    fork() return positive value in parent process and zero in child process
    The child process gets an exact copy of parent process and virtual address of 'a' doesn't  change in child process
    If creation was successful, it executes both processes (order of their execution depends on the OS)
    We can use ex1.sh to run this program 10 times!
**/
