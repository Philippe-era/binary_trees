#include "binary_trees.h"
#include "limits.h"

int binary_tree_is_avl(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
size_t height(const binary_tree_t *tree);



/**
 * height – The height will be measured
 * @tree: pointer to the tree
 *
 * Return: if tree is null the it is useless
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t light_node = 0, ready_node = 0;

		light_node = tree->left ? 1 + height(tree->left) : 1;
		ready_node = tree->right ? 1 + height(tree->right) : 1;
		return ((light_node > ready_node) ? light_node : ready_node);
	}
	return (0);
}

/**
 * is_avl_helper – valid AVL is working
 * @tree: tree will be pointed
 * @lo: lowest value to be executed
 * @hi: highest value to be executed
 *
 * Return: valid 1 uselss 0 or otherwise
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t light_node_check, right_node_check, different_node_check;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		light_node_check = height(tree->left);
		right_node_check = height(tree->right);
		different_node_check = light_node_check > right_node_check ? light_node_check - right_node_check : right_node_check - light_node_check;
		if (different_node_check > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl – if avl exists to be checked
 * @tree: tree to be evualted before execution
 *
 * Return: AVL if valid otherwise mize
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

