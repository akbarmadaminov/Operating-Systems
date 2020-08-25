#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;

    printf("Size and MaxValue of int: %lu %d\n", sizeof(a), a);
    printf("Size and MaxValue of float: %lu %f\n", sizeof(b), b);
    printf("Size and MaxValue of double: %lu %lf\n", sizeof(c), c);
}
