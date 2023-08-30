#include "binary_trees.h"

/**
 * binary_tree_depth - Depth of tree measured
 *@tree: pointer of the measured depth
 * Return: tree is NULL , failed operation
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
/* success if it = 0 */

	if (tree == NULL || tree->parent == NULL)
		return (0);
	else
		return (1 + binary_tree_depth(tree->parent));
}

