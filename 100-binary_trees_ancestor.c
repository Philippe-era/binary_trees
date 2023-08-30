#include "binary_trees.h"

/**
 * binary_tree_depth – the measurement of the binary tree
 *@tree: depth of tree node
 * Return: tree null = 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (1 + binary_tree_depth(tree->parent));
}
/**
 * binary_trees_ancestor – common ancestor returned
 * @first: number 1 node
 * @second: number 2 node
 * Return: lower common node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t height_node = 0, node_side = 0;
	const binary_tree_t *help_node = NULL;

	height_node = binary_tree_depth(first);
	node_side = binary_tree_depth(second);
	if (height_node && node_side)
	{
		if (height_node > node_side)
		{
			help_node = first;
			first = second;
			second = help_node;
		}
		while (first)
		{
			help_node = second;
			while (help_node)
			{
				if (first == help_node)
					return ((binary_tree_t *)first);
				help_node = help_node->parent;
			}
			first = first->parent;
		}
	}
	else
	{
		return (NULL);
	}
	return (NULL);
}

