#include "binary_trees.h"

/**
 * binary_tree_rotate_left -  a left rotation will be performed initially
 * @tree: points to the binary file
 * Return: new node will be returned
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *help_node, *temporary_node;

	if (tree == NULL)
		return (NULL);
	if (tree->right)
	{
		temporary_node = tree->right->left;
		help_node = tree->right;
		help_node->parent = tree->parent;
		help_node->left = tree;
		tree->parent = help_node;
		tree->right = temporary_node;
		if (temporary_node)
			temporary_node->parent = tree;
		return (help_node);
	}
	return (NULL);
}

