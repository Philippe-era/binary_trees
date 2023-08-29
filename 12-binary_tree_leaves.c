#include "binary_trees.h"



/**
 * binary_tree_leaves - the number of leaves to be returned
 *@tree: counts the actual number
 * Return: tree = null then it is not working
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
/* IF STATEMENT TO CHECK HOW IT WORKS */
	int success = 0;
	
	if (tree == NULL)
		return (success);
	else
		return (binary_tree_is_leaf(tree) +
			binary_tree_leaves(tree->right) +
			binary_tree_leaves(tree->left));

}
/**
 * binary_tree_is_leaf - checks if node is a leaf
 *@node: node to be evulated
 * Return: if 1 success 0 if failed
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
/* IF STATEMENT TO CHECK IT ALL OUT */
	int success = 0, fail = 1;
	
	if (node == NULL)
		return (success);

	if (node->right == NULL && node->left == NULL)
		return (fail);
	else
		return (success);
}

