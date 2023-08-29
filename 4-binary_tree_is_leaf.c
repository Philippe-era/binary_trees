#include "binary_trees.h"

/**
 * binary_tree_is_leaf -  function that checks if the binary is a leaf
 *@node: pointer to be checked
 * Return: if 1 success if 0 failed
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
int success = 1, fail = 0;
/* if block statement to decide whether it is a success or not */
	if (node == NULL)
		return (success);
/* if block statement to decide whether it is a fail or not */
	if (node->right == NULL && node->left == NULL)
		return (fail);
	else
		return (success);
}

