#include "binary_trees.h"
/**
 * binary_tree_height – height of tree to be returned
 *@tree: pointer to the tree
 * Return: tree is null then it is 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left_tree = 1, right_tree = 1;

		if (tree->right_tree)
			right_tree +=  binary_tree_height(tree->right);
		if (tree->left_tree)
			left_tree +=  binary_tree_height(tree->left);
		if (left_tree > right_tree)
			return (left_tree);
		else
			return (right_tree);
	}
	else
		return (0);
}
/**
 * binary_tree_balance – balance factor will be measured
 *@tree: tree will be located
 * Return: Always return 0 success
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_height(tree->left)
		- binary_tree_height(tree->right));
}

