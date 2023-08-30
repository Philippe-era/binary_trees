#include "binary_trees.h"

/**
 * array_to_bst – construction of a new binary array
 * @array: array to be changed
 * @size: counts the number of elements in the array
 * Return: root node to be pointed
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree_created;
	size_t num_node;

	if (array == NULL)
		return (NULL);
	tree_created = NULL;
	for (num_node = 0; num_node < size; num_node++)
	{
		bst_insert(&tree_created, array[num_node]);
	}
	return (tree_created);
}

