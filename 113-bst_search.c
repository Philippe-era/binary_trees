#include "binary_trees.h"
/**
 * bst_search -node will be found from binary search
 * @tree: root of the tree to be analyzed
 * @value: location of the node
 * Return: Success is = 1 , Fail = other
 */
bst_t *bst_search(const bst_t *tree, int value)
{

	if (tree == NULL)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
	return (NULL);
}

