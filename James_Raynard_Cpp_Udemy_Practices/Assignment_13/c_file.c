#include <stdio.h>

void print_array(int arr[], int size) {
    int i=0;
    for (i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
}

void print_map(int arr_1[], int arr_2[], int size) {
    int i = 0;
    for (i=0; i<size; i++) {
        printf("%d->%d\n", arr_1[i], arr_2[i]);
    }
}