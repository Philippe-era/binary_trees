#include "binary_trees.h"

/**
 * binary_tree_height – height of tree to be measured
 *@tree: points to the root
 * Return: tree null = failed
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
/* declaration of variables */
		int left_tree = 0, right_tree = 0, success = 0;

		if (tree->right_tree)
			right_tree = 1 + binary_tree_height(tree->right_tree);
		if (tree->left_tree)
			left = 1 + binary_tree_height(tree->left_tree);
		if (left > right_tree)
			return (left_tree);
		else
			return (right_tree);
	}
	else
		return (success);
}

