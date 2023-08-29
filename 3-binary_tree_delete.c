#include "binary_trees.h"

/**
 * binary_tree_delete – The entire binary will be deleted
 *@tree: the node that needs to be deleted will be deleted
 */
void binary_tree_delete(binary_tree_t *tree)
{
/* if statement that deletes the tree at hand */
	if (tree)
	{
		binary_tree_delete(tree->right);
		binary_tree_delete(tree->left);
/* frees the tree */
		free(tree);
	}
}


