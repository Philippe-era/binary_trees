#include "binary_trees.h"

/**
 * binary_tree_inorder – binary inorder check
 *@tree: the tree pointer created
 *@func: function that is created
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
/* if statement checked */
	if (tree && func)
	{
/* binary prototype */
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}

