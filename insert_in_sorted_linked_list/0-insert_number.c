#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * insert_node - function in C that inserts a number into a sorted singly linked list.
 * @head: head of the linked list.
 * @number: number to insert.
 * Return: address of the new node or NULL if it failed.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_list;
	listint_t *current;

    if (head == NULL)
    {
        return (NULL);
    }else
    {
        current = *head;
        new_list = malloc(sizeof(listint_t));
        if (new_list == NULL)
            return (NULL);
        new_list->n = number;
        while (current && current->next && current->next->n < number)
            current = current->next;
        if ((current == NULL) || (number < current->n))
        {
            new_list->next = *head;
            *head = new_list;
        }
        else
        {
            new_list->next = current->next;
            current->next = new_list;
        }
        return (new_list);
    }

}
