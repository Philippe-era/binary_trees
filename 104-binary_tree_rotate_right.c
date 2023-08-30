#include "binary_trees.h"

/**
 * binary_tree_rotate_right - right rotation will be performed
 * @tree: pointer to the binary tree
 * Return: returns the binary tree involved
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *help_node, *temporary_node;

	if (tree == NULL)
		return (NULL);
	if (tree->left)
	{
		temporary_node = tree->left->right;
		help_node = tree->left;
		help_node->parent = tree->parent;
		help_node->right = tree;
		tree->parent = help_node;
		tree->left = temporary_node;
		if (temporary_node)
			temporary_node->parent = tree;
		return (help_node);
	}
	return (NULL);
}

