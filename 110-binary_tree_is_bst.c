#include "binary_trees.h"
/**
 * find_node –the node will be found with this function
 * @root: analysed root to be checked
 * @node: node we locating
 * Return: 1 if success 0 if fail
 */
int find_node(binary_tree_t *root, binary_tree_t *node)
{

	if (root == NULL)
		return (0);
	if (node == root)
		return (1);
	if (node->n < root->n)
		return (find_node(root->left, node));
	if (node->n > root->n)
		return (find_node(root->right, node));
	return (0);
}
/**
 * croos_tree – tree crossing checked to be evulated
 * @root: node of the tree checked
 * @node: node to be analyzed
 * Return: 1 if success
 */
int croos_tree(binary_tree_t *root, binary_tree_t *node)
{
	if (root && node)
	{
		int help_node = 0;

		help_node = find_node(root, node);
		if (node->left)
			help_node &= croos_tree(root, node->left);
		if (node->right)
			help_node &= croos_tree(root, node->right);
		return (help_node);
	}
	return (0);
}
/**
 * binary_tree_is_bst – checks the tree if it is okay
 * @tree: tree to be checked
 * Return: 1 if success
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (croos_tree((binary_tree_t *)tree, (binary_tree_t *)tree));
}

