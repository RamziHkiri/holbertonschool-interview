#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle
 * @list: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
listint_t *first = list;
listint_t *second = list;

while (first != NULL && first->next != NULL)
{
second = second->next;
first = first->next->next;
if (second == first)
return (1);
}
return (0);
}
