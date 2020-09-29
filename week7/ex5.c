#include <stdio.h>
#include <stdlib.h>

int main() {
    char **s;
    char foo[] = "Hello World";

    s = malloc(11*sizeof(char)); /// We should allocate memory for s before using

    *s = foo;

    printf("*s is %s\n", *s); /// 's' -> '*s'  we need a pointer to char array, but s is a type char**

    s[0] = foo;
    printf("s[0] is %c\n", *s[0]);  /// change '%s' -> '%c' to print only first symbol of the string, and also 's[0]' -> '*s[0]'
    return(0);
}


