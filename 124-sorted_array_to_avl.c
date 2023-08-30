#include "binary_trees.h"

/**
 * binary_tree_size – size of binary tree
 *
 * @tree: root of tree
 * Return: if size of tree is null = 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * tree_is_complete – if tree completed success
 * @tree: tree pointer
 * @i: initial
 * @cnodes: count nodes
 * Return: Always 1 Success
 */
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes)
{
	if (tree == NULL)
		return (1);

	if (i >= cnodes)
		return (0);

	return (tree_is_complete(tree->left, (2 * i) + 1, cnodes) &&
		tree_is_complete(tree->right, (2 * i) + 2, cnodes));
}


/**
 * binary_tree_is_complete - calls to tree_is_complete function
 *
 * @tree: pointer of tree root
 * Return: 1 Success 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t count_nodes;

	if (tree == NULL)
		return (0);

	count_nodes = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, count_nodes));
}

/**
 * check_parent – parent greater than kids
 * @tree: tree pointer
 * Return: 1 success 0 otherwise
 */
int check_parent(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * binary_tree_is_heap – maximum heap checked
 * @tree: pointer to tree
 * Return: 1 tree is Max
*/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_complete(tree))
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

