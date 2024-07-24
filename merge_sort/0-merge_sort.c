#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of `array[]`.
 * @array: Array to be sorted.
 * @left: Left subarray.
 * @right: Right subarray.
 * @left_size: Size of the left subarray.
 * @right_size: Size of the right subarray.
 */
void merge(int *array, int *left, int *right, size_t left_size, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            array[k++] = left[i++];
        else
            array[k++] = right[j++];
    }

    while (i < left_size)
        array[k++] = left[i++];

    while (j < right_size)
        array[k++] = right[j++];

    printf("[Done]: ");
    print_array(array, left_size + right_size);
}

/**
 * merge_sort - Sorts an array in ascending order using the Merge Sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
    size_t mid, i, j;
    int *left, *right;
    if (size < 2)
        return;

    mid = size / 2;
    left = malloc(mid * sizeof(int));
    right = malloc((size - mid) * sizeof(int));

    if (!left || !right)
    {
        free(left);
        free(right);
        return;
    }

    for (i = 0; i < mid; i++)
        left[i] = array[i];
    for (j = mid; j < size; j++)
        right[j - mid] = array[j];

    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merge(array, left, right, mid, size - mid);

    free(left);
    free(right);
}
