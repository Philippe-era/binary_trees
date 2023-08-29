#include "binary_trees.h"

/**
 * binary_tree_node – This function creates the tree node function
 * @parent: pointer of parent will be created
 * value: the value you to be formed
 * Return:A pointer or function will be formed
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
