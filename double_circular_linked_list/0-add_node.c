#include "list.h"
List *add_node_end(List **list, char *str) {
    List *new_node;
    
    new_node = malloc(sizeof(List));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->str = str;
    if (new_node->str == NULL) {
        free(new_node);
        return NULL;
    }
    
    new_node->next = new_node;
    new_node->prev = new_node;
    
    if (*list == NULL) {
        *list = new_node;
    } else {
        List *last = (*list)->prev;
        
        last->next = new_node;
        new_node->prev = last;
        new_node->next = *list;
        (*list)->prev = new_node;
    }
    
    return new_node;
}

/**
 * add_node_begin - Adds a new node to the beginning of a double circular linked list.
 * @list: The list to modify.
 * @str: The string to copy into the new node.
 *
 * Return: Address of the new node, or NULL on failure.
 */
List *add_node_begin(List **list, char *str) {
    List *new_node;
    
    new_node = malloc(sizeof(List));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->str = str;
    if (new_node->str == NULL) {
        free(new_node);
        return NULL;
    }
    
    if (*list == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
        *list = new_node;
    } else {
        List *last = (*list)->prev;
        
        new_node->next = *list;
        new_node->prev = last;
        (*list)->prev = new_node;
        last->next = new_node;
        *list = new_node;
    }
    
    return new_node;
}