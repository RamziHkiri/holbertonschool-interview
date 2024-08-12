#include "binary_trees.h"

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/


// Definition of the heap node
typedef struct heap_s {
    int n;
    struct heap_s *parent;
    struct heap_s *left;
    struct heap_s *right;
} heap_t;

// Function prototypes
void heapify_down(heap_t *node);
heap_t *get_last_node(heap_t *root);
void remove_last_node(heap_t *root, heap_t *last_node);

int heap_extract(heap_t **root) {
    if (root == NULL || *root == NULL) {
        return 0;
    }
    
    int root_value = (*root)->n;
    
    // Find the last node in level-order
    heap_t *last_node = get_last_node(*root);
    
    // If the last node is the root, free it and set root to NULL
    if (last_node == *root) {
        free(*root);
        *root = NULL;
        return root_value;
    }
    
    // Replace root node's value with last node's value
    (*root)->n = last_node->n;
    
    // Remove the last node from the heap
    remove_last_node(*root, last_node);
    free(last_node);
    
    // Restore the heap property by heapifying down from the root
    heapify_down(*root);
    
    return root_value;
}

void heapify_down(heap_t *node) {
    if (node == NULL) {
        return;
    }
    
    heap_t *largest = node;
    if (node->left != NULL && node->left->n > largest->n) {
        largest = node->left;
    }
    if (node->right != NULL && node->right->n > largest->n) {
        largest = node->right;
    }
    
    if (largest != node) {
        int temp = node->n;
        node->n = largest->n;
        largest->n = temp;
        heapify_down(largest);
    }
}

heap_t *get_last_node(heap_t *root) {
    // Implement a queue to perform level-order traversal
    heap_t **queue = malloc(1000 * sizeof(heap_t *));
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    heap_t *last_node = NULL;
    while (front < rear) {
        last_node = queue[front++];
        if (last_node->left != NULL) {
            queue[rear++] = last_node->left;
        }
        if (last_node->right != NULL) {
            queue[rear++] = last_node->right;
        }
    }
    
    free(queue);
    return last_node;
}

void remove_last_node(heap_t *root, heap_t *last_node) {
    // Implement a queue to perform level-order traversal
    heap_t **queue = malloc(1000 * sizeof(heap_t *));
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    while (front < rear) {
        heap_t *current = queue[front++];
        if (current->left == last_node) {
            current->left = NULL;
            break;
        } else if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right == last_node) {
            current->right = NULL;
            break;
        } else if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    
    free(queue);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 *sort_heap - Sorts the heap in descending order.
 *@current: Current node being checked.
 *Return: Pointer to the sorted heap.
 **/
heap_t *sort_heap(heap_t *current)
{
	int temp;

	while (current->left || current->right)
	{
		if (!current->right || current->left->n > current->right->n)
		{
			temp = current->n;
			current->n = current->left->n;
			current->left->n = temp;
			current = current->left;
		}
		else if (!current->left || current->left->n < current->right->n)
		{
			temp = current->n;
			current->n = current->right->n;
			current->right->n = temp;
			current = current->right;
		}
	}

	return (current);
}

/**
 *preorder_traversal - Performs a preorder traversal of the heap.
 *@root: Root node of the heap.
 *@node: Reference to the node at the specified level.
 *@target_level: Target level to be found.
 *@current_level: Current level being checked during traversal.
 **/
void preorder_traversal(heap_t *root, heap_t **node, size_t
target_level, size_t current_level)
{
	if (!root)
		return;
	if (current_level == target_level)
		*
		node = root;
	current_level++;
	if (root->left)
		preorder_traversal(root->left, node, target_level, current_level);
	if (root->right)
		preorder_traversal(root->right, node, target_level, current_level);
}

/**
 *get_tree_height - Calculates the height of a binary tree.
 *@tree: Pointer to the root of the binary tree.
 *Return: Height of the binary tree.
 */
static size_t get_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	left_height = tree->left ? 1 + get_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + get_tree_height(tree->right) : 0;
	return (left_height > right_height ? left_height : right_height);
}

/**
 *heap_extract - Extracts the maximum value from the heap.
 *@root: Pointer to the root of the heap.
 *Return: The extracted maximum value.
 */
int heap_extract(heap_t **root)
{
	int extracted_value;
	heap_t *current, *node;

	if (!root || !*root)
		return (0);

	current = *root;
	extracted_value = current->n;

	if (!current->left && !current->right)
	{
		*root = NULL;
		free(current);
		return (extracted_value);
	}

	preorder_traversal(current, &node, get_tree_height(current), 0);
	current = sort_heap(current);
	current->n = node->n;

	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;

	free(node);
	return (extracted_value);
}