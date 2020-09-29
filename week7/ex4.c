#include <stdlib.h>
#include <stdio.h>

int* real(int *a, int n2) {
    int n1 = sizeof(a);
    int* b = malloc(n2*sizeof(int));

    for (int i = 0; i < n2 && i < n1; i++) {
        b[i] = a[i];
    }
    free(a);
    return b;
}

int main(){
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

    int* a1 = malloc(n1 * sizeof(int));
	int i;
	for(i=0; i<n1; i++){
        a1[i]=100;
        printf("%d ", a1[i]);
	}
    printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);
    a1 = real(a1, n2);
    for (i = n1; i < n2; i++)
        a1[i] = 0;

    for(i=0; i<n2;i++){
		printf("%d ", a1[i]);
	}
	printf("\n");
    return 0;
}

