#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#define N 1000

typedef struct node {
	int inum;
	char *name;
} Node;

int comp(const void* p, const void* q) {
	return ((Node*)p)->inum < ((Node*)q)->inum;
}

int main() {
    DIR *dir = opendir("./tmp/");
    int cnt = 0;                            /// Counts number of files
    Node files[N];                          /// Stores Name and i-node number of files
    struct dirent *nx;

    while ((nx = readdir(dir)) != NULL) {           /// Reads next entry until the end of the directory
        files[cnt].inum = nx->d_ino;                   /// Stores i-node number and name of our entry
        files[cnt].name = nx->d_name;
        cnt++;
    }

    qsort(files, cnt, sizeof(Node), comp);          /// Sorts files in ascending order or their i-node number (used to group files with the same inum)
    for (int i = 0; i < cnt; ++i) {
        int j = i;
        while (j + 1 < cnt && files[j + 1].inum == files[i].inum)           /// after sorting all files with same inum occurs consequently
            j++;                                                            /// so it finds this segment of files

        if (i == j) continue;                                   /// To skip i-nodes with a hard link count less than 2

        printf("Files with inum %d: ", files[i].inum);
        while (i < j) {                                         /// Prints all files with i-node number files[i].inum
            printf("%s ", files[i].name);
            i++;
        }
        printf("%s\n", files[i].name);
        i = j;
    }
}
