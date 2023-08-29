#include "binary_trees.h"

/**
 * binary_tree_is_root – checks if it is a root ot not
 * @node: node to be analysed
 * Return: 1 if success 0 if not a success
 */
int binary_tree_is_root(const binary_tree_t *node)
{
/* if block to check if it is a node or not */
	if (node == NULL)
		return (0);
/* if block to check if it is a node or not */
	if (node->parent == NULL)
		return (1);
	else
		return (0);
}

