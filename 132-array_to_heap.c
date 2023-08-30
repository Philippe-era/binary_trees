#include "binary_trees.h"

/**
 * array_to_heap – Max Tree Constructed
 * @array: 1st element in the array
 * @size: count of array
 * Return: root avl node
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *tree_new;
	size_t initial;

	tree_new = NULL;

	for (initial = 0; initial < size; initial++)
	{
		heap_insert(&tree_new, array[initial]);
	}

	return (tree_new);
}

