#include "binary_trees.h"

/**
 * binary_tree_sibling - locates the sibling that is lost
 *@node: pointer to the sibling found
 * Return: pointer to the sibling node.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
/* if statement to dela with conditions */
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->right == node)
		return (node->parent->left);
	else
		return (node->parent->right);

}

