#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

#define sz 1024

// Read from standard input and write to standard output and files
int my_tee(bool append, int size, char *argv[]) {

    char buf[sz];
	memset(buf, 0, sz);

	// Open output files
	FILE *output_files[size];
	for (int i = 0; i < size; i++) {
		output_files[i] = fopen(argv[i], (append ? "a" : "w"));
    }

	// Read from standart input
	int read_size;
	while ((read_size = read(0, buf, sz)) > 0) {
		// Write buf to every file and stdout
		for (int i = 0; i < size; i++)
			fprintf(output_files[i], "%s", buf);
		printf("%s\n", buf);

		// Reset buffer
		memset(buf, 0, sz);
	}

    // Close output files
	for (int i = 0; i < size; i++) {
		fclose(output_files[i]);
	}
	return 0;
}

int main(int argc, char *argv[]) {
	// Check input format
	if (argc < 2) {
		printf("usage: %s [-a] <file>…​\n", argv[0]);
		return 1;
	}

	// Check parameter [-a]
	bool append = !(bool)(strcmp(argv[1], "-a"));
	int frst = 1 + (int)append;

	// Start tee function for multiple output files
	return my_tee(append, argc - frst, argv + frst);
}
