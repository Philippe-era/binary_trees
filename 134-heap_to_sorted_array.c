#include "binary_trees.h"

/**
* count_h_nodes – count of elements in tree
* @root: root new
* Return: count tree nodes
 */
int count_h_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_h_nodes(root->left) +
		    count_h_nodes(root->right));
}

/**
 * heap_to_sorted_array – max heap created
 * @heap: heap pointer found
 * @size: array size
 *
 * Return: Pointer to array of integeres
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int initial, nodes, *array_new = NULL;

	*size = 0;
	if (!heap)
		return (NULL);

	nodes = count_h_nodes(heap);
	array_new = malloc(sizeof(*array_new) * nodes);
	if (!array_new)
		return (NULL);

	*size = nodes;
	for (initial = 0; initial < nodes; initial++)
		array_new[initial] = heap_extract(&heap);

	return (array_new);
}

