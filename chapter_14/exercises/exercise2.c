/* Uses macros to find the size of an array */

#include <stdio.h>

#define SIZE(a) ( (int) (sizeof(a) / sizeof(a[0])))

int main(void)
{
    int int_arr[5] = {2, 9};
    float flt_arr[8] = {0.0};
    double db_arr[10] = {0.0};
    char char_arr[16] = {'\0'};

    printf("size of int_arr: %d\n", SIZE(int_arr));
    printf("size of flt_arr: %d\n", SIZE(flt_arr));
    printf("size of db_arr: %d\n", SIZE(db_arr));
    printf("size of char_arr: %d\n", SIZE(char_arr));

    return 0;
}