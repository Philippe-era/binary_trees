#include "binary_trees.h"

/**
 * binary_tree_is_full – if binary is full
 *@tree: node tree to be checked
 * Return: if tree is null it is equal to 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int success = 0, fail = 1;
	
	if (tree == NULL)
		return (success);
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	if (tree->left == NULL && tree->right == NULL)
		return (fail);
	return (success);
}

