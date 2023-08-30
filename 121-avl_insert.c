#include "binary_trees.h"
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);
size_t height(const binary_tree_t *tree);


/**
 * height – binary tree to be measured in height
 * @tree: measures tree in the context
 * Return: If tree is NULL, your function must return 0
 */
size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t light_node = 0, ready_node = 0;

		light_node = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		ready_node = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((light_node > ready_node) ? light_node : ready_node);
	}
	return (0);
}

/**
 * balance – balance to be weighed
 * @tree: tree to check
 *
 * Return: tree = null 0 is nothing
 */
int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive – value added into binary
 * @tree: pointer tree
 * @parent: pointer parent
 * @new: pointer new
 * @value: pointer value
 *
 * Return: new pointer.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int node_replace;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	node_replace = balance(*tree);
	if (node_replace > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (node_replace < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (node_replace > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (node_replace < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert – a value will be inserted into the avl
 * @tree: pointer tree
 * @value: pointer value to be created
 *
 * Return: pointer inserted
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new_node, value);
	return (new_node);
}

