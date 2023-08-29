#include "binary_trees.h"

/**
 * binary_tree_size – size of binary tree
 * @tree: tree pointed
 * Return: tree returns 0 instead of null
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
/* declaration of variables */
	int success = 0;
	
	if (tree == NULL)
		return (success);
	{
/* prototype created */
		size_t left_tree, right_tree;

		left_tree = binary_tree_size(tree->left);
		right_tree = binary_tree_size(tree->right);
		return (1 + left_tree + right_tree);
	}
}

