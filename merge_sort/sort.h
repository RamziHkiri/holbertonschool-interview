#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int *temp, size_t left, size_t mid, size_t right);

#endif
