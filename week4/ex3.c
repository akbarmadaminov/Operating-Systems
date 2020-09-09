#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	char command[110];
	printf("> ");
    /// It can read and run only commands without parameters
    while (scanf("%s", command) > 0) {
        system(command);
        printf("> ");
    }
    return 0;
}
