#include "binary_trees.h"

/**
 * binary_tree_size – binary tree measured
 * @tree: pointer root
 * Return: size of tree is 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * tree_is_complete – tree check to be completed
 * @tree: tree root pointed too
 * @i: node number
 * @cnodes: node count
 * Return: 1 Success
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
 * binary_tree_is_complete – binary will be completed
 *
 * @tree: pointer tree node
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
 * check_parent – parent greater or not
 *
 * @tree: tree pointer
 * Return: 1 if parent is greater
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
 * binary_tree_is_heap – Max binary heap
 *
 * @tree: root tree pointed out
 * Return: 1 if Max is matched
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_complete(tree))
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

