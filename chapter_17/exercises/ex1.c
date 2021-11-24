#include <stdio.h>
#include <stdlib.h>

void my_malloc(void* ptr);

int main(void) {
	int *ptr = malloc(5 * sizeof(int));
	char *ptr_char = malloc(5 * sizeof(char));
	double *ptr_dou = malloc(5 * sizeof(double));
	my_malloc(ptr);
	my_malloc(ptr_char);
	my_malloc(ptr_char);
	printf("All is well\n");
	return 0;
}

void my_malloc(void* ptr) {
	if (ptr == NULL) {
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
}

