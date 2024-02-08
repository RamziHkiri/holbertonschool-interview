#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int is_palindrome(listint_t **head){
   listint_t *current = *head;  

    int length = 0;
    int array[10000];
    int i;
    while (current != NULL)
	{
		array[length] = current->n;
		current = current->next;
		length++;
	}

    for (i = 0; i < (length / 2); i++)
	{
		if (array[i] != array[length - i -1])
			return (0);
	}
	return (1);
}