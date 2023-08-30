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
		int left_tree = 0, right_tree = 0;

		if (tree->right)
			right_tree = 1 + binary_tree_height(tree->right);
		if (tree->left)
			left_tree = 1 + binary_tree_height(tree->left);
		if (left_tree > right_tree)
			return (left_tree);
		else
			return (right_tree);
	}
	else
		return (0);
}

