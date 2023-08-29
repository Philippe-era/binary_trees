#include "binary_trees.h"

/**
 * binary_tree_insert_left – function into the left node
 *@parent: pointer inserted into the left node
 *@value: value created to node
 * Return: Created node will be pointed to
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
/* binary prototype */
	binary_tree_t *node_check = NULL;
/* if statement for the parent node */
	if (parent == NULL)
		return (NULL);
/* Assigning node check */
	node_check = malloc(sizeof(binary_tree_t));
	if (node_check == NULL)
		return (NULL);
	node_check->n = value;
	node_check->parent = parent;
	node_check->left = NULL;
	node_check->right = NULL;
	if (parent->left == NULL)
		parent->left = node_check;
	else
	{
		node_check->left = parent->left;
		parent->left = node_check;
		node_check->left->parent = node_check;
	}
/* the return type */
	return (node_check);
}

