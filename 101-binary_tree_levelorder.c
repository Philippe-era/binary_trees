#include "binary_trees.h"
/**
 * binary_tree_height – measurement of binary tree
 *@tree: pointer to tree
 * Return: if tree = 0 it is null
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left_tree = 0, right_tree = 0;

		if (tree->right_tree)
			right_tree = 1 + binary_tree_height(tree->right);
		if (tree->left_tree)
			left_tree = 1 + binary_tree_height(tree->left);
		if (left_tree > right_tree)
			return (left_tree);
		else
			return (right_tree);
	}
	else
		return (0);
}
/**
 * print_at_level – display node , specific node
 * @tree: tree will be printed
 * @func: function to be created
 * @level: level to be printed
 */
void print_at_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree && func)
	{
		if (level == 1)
			func(tree->n);
		else
		{
			print_at_level(tree->left, func, level - 1);
			print_at_level(tree->right, func, level - 1);
		}
	}

}

/**
 * binary_tree_levelorder – binary level transveral
 * @tree: tree node we will leave it
 * @func: recursive function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t help_node = 0, initial_node = 1;

	if (tree && func)
	{
		help_node = binary_tree_height(tree);
		while (initial_node <= help_node + 1)
		{
			print_at_level(tree, func, initial);
			initial++;
		}
	}

}

