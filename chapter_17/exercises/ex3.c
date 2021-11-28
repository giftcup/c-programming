/**
 * @brief Dynamically allocates memory for an array
 *        an initializes it to a particular value
 */ 
#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int initial_value);

int main(void) {
    int size_of_array, initial_value;
    int *array;

    printf("Enter size of array: ");
    scanf("%d", &size_of_array);
    printf("Enter initial value: ");
    scanf("%d", &initial_value);

    array = create_array(size_of_array, initial_value);
    for (int i = 0; i < size_of_array; i++)
        printf("%d ", array[i]);
    printf("\n");
    
    return 0;
}

/**
 * @brief allocates memory for an array of integers
 *        and initializes it to a particular value
 * @param n size of the array to allocated
 * @param init initial value the array is to hold
 * @return pointer to array
 */ 
int *create_array(int n, int init) {
    int *arr = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        arr[i] = init;
    
    return arr;
}
