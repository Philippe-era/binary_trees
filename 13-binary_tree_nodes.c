#include "binary_trees.h"

/**
 * binary_tree_nodes – counts child nodes
 *@tree: pointers checked
 * Return: tree null = 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
/* if statements that work with the situation */
	if (tree == NULL)
		return (0);
	if (tree->right != NULL || tree->left != NULL)
		return  (1 + binary_tree_nodes(tree->right) +
			 binary_tree_nodes(tree->left));
	return (0);
}

