#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	char command[110];
    printf("> ");
    /// It reads a whole line to get a command and it's parameters
    while (fgets(command, 100, stdin) != NULL) {
        system(command);
        printf("> ");
    }
    return 0;
}
