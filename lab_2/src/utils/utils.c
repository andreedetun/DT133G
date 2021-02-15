//
// Created by an_de on 2021-02-15.
//

#include "utils.h"

void swap(int *a, int *b) {
    int temp = *b;

    *b = *a;
    *a = temp;
}