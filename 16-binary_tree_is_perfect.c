#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree.
 *@tree: node root
 * Return: null tree must be equal to 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
/* if statement to deal with all these conditions */
	if (tree)
	{
		int left_pointer = 0, right_pointer = 0;

		if (tree->right)
			right_pointer = 1 + binary_tree_height(tree->right);
		if (tree->left)
			left_pointer = 1 + binary_tree_height(tree->left);
		if (left_pointer > right_pointer)
			return (left_pointer);
		else
			return (right_pointer);
	}
	else
		return (0);
}
/**
 * binary_tree_size - measures the size of a binary tree.
 *@tree: pointer to the root node of the tree to measure the size.
 * Return: if tree is NULL, must return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	{
		size_t left_tree, right_tree;

		left_tree = binary_tree_size(tree->left);
		right_tree = binary_tree_size(tree->right);
		return (1 + left_tree + right_tree);
	}
}
/**
 * binary_tree_is_perfect –binary check if perfect
 *@tree: pointer root
 * Return: if tree is 0 it is null
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t help_root = 0, binary_perfect = 0;

	if (tree == NULL)
		return (0);
	binary_perfect = binary_tree_height(tree);
	binary_perfect = (1 << (help_root + 1)) - 1;
	if (binary_perfect == binary_tree_size(tree))
		return (1);
	else
		return (0);
}

