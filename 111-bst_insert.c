#include "binary_trees.h"
/**
 * bst_insert – value will be added to the binary search
 * @tree: double pointer to be checked
 * @value: value created in the
 * Return: Success Always 0
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *help_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	help_node = *tree;
	if (value < help_node->n)
	{
		if (help_node->left == NULL)
		{
			help_node->left = binary_tree_node(help_node, value);
			return (help_node->left);
		}
		return (bst_insert(&(help_node->left), value));
	}
	if (value > help_node->n)
	{
		if (help_node->right == NULL)
		{
			help_node->right = binary_tree_node(help_node, value);
			return (help_node->right);
		}
		return (bst_insert(&(help_node->right), value));
	}
	return (NULL);
}

