#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* advanced_binary - function search using binary search 
 *
 * @array: sorted array of integer
 * @size: size of the array
 * @value: int to search about
 *
 * Return: length of printed tree after process
 */

int advanced_binary(int *array, size_t size, int value){

    size_t i = 0;

    while(size - 1 > i && array[i]!=value) {
        i++;
    }
    if (array[i]==value)
    {
       return i;
    }
    return -1;
}