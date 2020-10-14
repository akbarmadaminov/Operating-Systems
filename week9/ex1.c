#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int n;              /// Number of page frames
int miss, hit;      /// Miss & Hit counters

struct frame{
    int rbit, page;           /// Referenced bit and Page number of a frame
};

int main() {
    FILE* file;
    file = fopen("input.txt", "r");

    printf("Enter number of page frames: ");
    scanf("%d", &n);

    struct frame* f = malloc(n * sizeof(struct frame));     /// Allocates memory for n frames

    for (int i = 0; i < n; i++) {   /// Initializes all frames
        f[i].rbit = 0;
        f[i].page = -1;             /// As all page numbers are non-negative
    }

    int p;      /// Received page number in every step

    while (fscanf(file, "%d", &p) != EOF) {     /// Reads next page number from input.txt

        for (int i = 0; i < n; i++) {           /// Shifts referenced bits to the right
            f[i].rbit >>= 1;
        }

        int in = -1;                     /// Index of frame to which we will refer

        for (int i = 0; i < n; i++) {   /// Checks if we have frame with the same page number with the received page number
            if (f[i].page == p) {
                in = i;
            }
        }

        if (in != -1) {
            hit++;
        } else {
            miss++;
            in = 0;
            /// If we have free frames, we will use them
            /// Otherwise it finds not the oldest, but any frame we didn't use recently
            for (int i = 1; i < n; i++) {
                if (f[i].rbit < f[in].rbit ||
                    f[i].rbit == f[in].rbit && f[i].page < f[in].page)    /// If rbits are equal we choose frame with minimal page number to give priority to free frames
                    in = i;
            }
            f[in].page = p;
        }
        f[in].rbit |= (1 << 7);         /// Changes frame's bit referenced in this step
    }
    double ratio = hit*1.0 / miss;          /// Hit/MISS ratio
    printf("Hits: %d\nMisses: %d\nRatio: %lf\n", hit, miss, ratio);
}
