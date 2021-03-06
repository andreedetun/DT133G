#include <stdio.h>
#include <stdlib.h>
#include "../../utils/utils.h"
#include "insertion.h"

void insertionSort(int *arr) {
    size_t size = arr[0];
    for (int i = 1; i < size; ++i) {
        int tmp = i;
        for (int j = i + 1; j <= size; ++j)
            if (arr[j] < arr[tmp])
                tmp = j;

        swap(&arr[i], &arr[tmp]);
    }
}