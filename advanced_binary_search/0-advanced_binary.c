#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* advanced_binary - function search using binary search
 *
 * @array: sorted array of integer
 * @size: size of the array
 * @value: int to search about
 *
 * Return: index of the searched value or -1 if not found
 */

int advanced_binary(int *array, size_t size, int value)
{
	int mid = ((size - 1) / 2), res = 0;
	size_t i = 0;

	if (array == NULL || size < 1)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i != (size - 1))
			printf(", ");
		else
			printf("\n");
	}

	if (array[mid] == value && mid == 0)
		return (mid);
	else if (size == 1)
		return (-1);

	if (array[mid] >= value)
		return (advanced_binary(array, mid + 1, value));

	mid++;
	res = advanced_binary(&array[mid], size - mid, value);
	if (res == -1)
		return (-1);
	return (mid + res);
}