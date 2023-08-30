#include "binary_trees.h"

/**
 * height – height of tree measured
 * @tree: pointer tree node
 * Return: tree height
 */
int height(const binary_tree_t *tree)
{
	int left_sibling = 0;
	int right_sibling = 0;

	if (tree == NULL)
		return (-1);

	left_sibling = height(tree->left);
	right_sibling = height(tree->right);

	if (left_sibling > right_sibling)
		return (left_sibling + 1);

	return (right_sibling + 1);
}

/**
 * binary_tree_is_perfect – if perfect return perfect
 *
 * @tree: root tree
 * Return: perfect tree
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree && height(tree->left) == height(tree->right))
	{
		if (height(tree->left) == -1)
			return (1);

		if ((tree->left && !((tree->left)->left) && !((tree->left)->right))
		    && (tree->right && !((tree->right)->left) && !((tree->right)->right)))
			return (1);

		if (tree && tree->left && tree->right)
			return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}

	return (0);
}

/**
 * swap – switch nodes between parent and child
 * @arg_node: node of parent
 * @arg_child: node of kids
 * Return: Nothing
*/
void swap(heap_t **arg_node, heap_t **arg_child)
{
	heap_t *node_check, *child, *node_kids, *left_node, *right_node, *parent;
	int siblings;

	node_check = *arg_node, child = *arg_child;
	if (child->n > node_check->n)
	{
		if (child->left)
			child->left->parent = node_check;
		if (child->right)
			child->right->parent = node_check;
		if (node_check->left == child)
			node_kids = node_check->right, siblings = 0;
		else
			node_kids = node_check->left, siblings = 1;
		left_node = child->left, right_node = child->right;
		if (siblings == 0)
		{
			child->right = node_kids;
			if (node_kids)
				node_kids->parent = child;
			child->left = node_check;
		}
		else
		{
			child->left = node_kids;
			if (node_kids)
				node_kids->parent = child;
			child->right = node_check;
		}
	if (node_check->parent)
		{
			if (node_check->parent->left == node_check)
				node_check->parent->left = child;
			else
				node_check->parent->right = child;
		}
		parent = node_check->parent; child->parent = parent;
		node_check->parent = child; node_check->left = left_node;
		node_check->right = right_node; *arg_node = child;
	}
}

/**
 * heap_insert – value insertion into Max HEAP
 * @value: inserted value
 * @root: root tree
 * Return: created node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node_create;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	if (binary_tree_is_perfect(*root) || !binary_tree_is_perfect((*root)->left))
	{
		if ((*root)->left)
		{
			node_create = heap_insert(&((*root)->left), value);
			swap(root, &((*root)->left));
			return (node_create);
		}
		else
		{
			node_create = (*root)->left = binary_tree_node(*root, value);
			swap(root, &((*root)->left));
			return (node_create);
		}
	}

	if ((*root)->right)
	{
		node_create = heap_insert(&((*root)->right), value);
		swap(root, (&(*root)->right));
		return (node_create);
	}
	else
	{
		node_create = (*root)->right = binary_tree_node(*root, value);
		swap(root, &((*root)->right));
		return (node_create);
	}

	return (NULL);
}

