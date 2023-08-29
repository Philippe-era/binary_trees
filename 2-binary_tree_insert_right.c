#include "binary_trees.h"

/**
 * binary_tree_insert_right – the right child sibling will be inserted
 *@parent: Pointer for the parent
 *@value: The new value to be createed
 * Return:  Always Success
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
/* BINARY TREE PROTOTYPOE */
	binary_tree_t *node_check = NULL;
/* IF STATEMENT FOR THE PARENT NODE */
	if (parent == NULL)
		return (NULL);
	node_check = malloc(sizeof(binary_tree_t));
	if (node_check == NULL)
		return (NULL);
/* POINTER TO NODE */
	node_check->n = value;
	node_check->parent = parent;
	node_check->left = NULL;
	node_check->right = NULL;
	if (parent->right == NULL)
		parent->right = node_check;
	else
	{
		node_check->right = parent->right;
		parent->right = node_check;
		node_check->right->parent = node_check;
	}
	return (node_check);
}

