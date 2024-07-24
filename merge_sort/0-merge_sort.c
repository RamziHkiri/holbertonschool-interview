#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of `array[]`.
 * @array: Array to be sorted.
 * @temp: Temporary array used for merging.
 * @left: Starting index of the left subarray.
 * @mid: Ending index of the left subarray.
 * @right: Ending index of the right subarray.
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
    size_t i = left, j = mid + 1, k = left;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array + left, mid - left + 1);
    printf("[right]: ");
    print_array(array + mid + 1, right - mid);

    while (i <= mid && j <= right)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid)
        temp[k++] = array[i++];

    while (j <= right)
        temp[k++] = array[j++];

    for (i = left; i <= right; i++)
        array[i] = temp[i];

    printf("[Done]: ");
    print_array(array + left, right - left + 1);
}

/**
 * merge_sort_recursive - Recursive function for merge sort.
 * @array: Array to be sorted.
 * @temp: Temporary array used for merging.
 * @left: Starting index of the array segment to be sorted.
 * @right: Ending index of the array segment to be sorted.
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
    size_t mid;
    if (left >= right)
        return;

    mid = left + (right - left) / 2;

    merge_sort_recursive(array, temp, left, mid);
    merge_sort_recursive(array, temp, mid + 1, right);
    merge(array, temp, left, mid, right);
}

/**
 * merge_sort - Sorts an array in ascending order using the Merge Sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
    int *temp;
    if (!array || size < 2)
        return;

    temp = malloc(size * sizeof(int));
    if (!temp)
        return;

    merge_sort_recursive(array, temp, 0, size - 1);
    free(temp);
}
