#include "binary_trees.h"

/**
 * binary_tree_postorder – binary post order
 *@tree: tree will be pointed to
 *@func: pointer to function
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	/* function of the tree and function will be created */
	if (tree && func)
	{
/* post order creation */
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}

