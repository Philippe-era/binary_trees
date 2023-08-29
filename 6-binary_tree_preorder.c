#include "binary_trees.h"

/**
 * binary_tree_preorder – binary pre order transversal
 * @tree: pointer tree
 *@func: recursive function
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
/* if will return the right function */
	if (tree && func)
	{
/* the function to be create */
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}

