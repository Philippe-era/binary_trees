#include "binary_trees.h"

/**
 * binary_tree_uncle - uncle node found
 *@node: pointer locating uncle
 * Return: uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);
	return (binary_tree_sibling(node->parent));
}


/**
 * binary_tree_sibling - finds the sibling
 *@node: locates to the sibling
 * Return: sibling pointer node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->right == node)
		return (node->parent->left);
	else
		return (node->parent->right);

}

