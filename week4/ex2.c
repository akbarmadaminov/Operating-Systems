#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int t = 3;
	for (int i = 0; i < t; ++i) {
		fork();
	}
    sleep(5);
}
/**
    After each fork() call, number of processes doubles and they continue to execute following code after fork() separately.
    So if we call fork() t times, then number of processes will be 2^t.
    (In this program if t = 3, then number of processes will be 8, and 32 if we call fork() 5 times)
    When t = 3;
    7 more processes created except the initial.
    init─┬─bash───bash─┬─ex2─┬─ex2─┬─ex2───ex2
     │             │     │     └─ex2
     │             │     ├─ex2───ex2
     │             │     └─ex2
     │             └─pstree

**/
