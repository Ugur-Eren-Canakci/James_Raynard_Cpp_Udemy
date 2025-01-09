#include "c_func.h"
#include <stdio.h>

void print_array(int arr[], int size) {
    int i=0;
    for (i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    
}

