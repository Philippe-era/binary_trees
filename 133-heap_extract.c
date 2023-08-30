#include "binary_trees.h"

/**
 * count_heap_nodes – number of nodes in heap
 * @root: node tree pointed
 *
 * Return: count nodes
 */
int count_heap_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_heap_nodes(root->left) +
		    count_heap_nodes(root->right));
}


/**
 * bubble_down – node in right position
 * @parent: heap node pointed
 */
void bubble_down(heap_t *parent)
{
	int temporary_nodes;
	heap_t *first_born = NULL;

	if (!parent)
		return;

	while (parent && parent->left)
	{
		first_born = parent->left;

		if (parent->right && parent->right->n > parent->left->n)
			first_born = parent->right;

		if (first_born->n > parent->n)
		{
			temporary_nodes = parent->n;
			parent->n = first_born->n;
			first_born->n = temporary_nodes;
		}

		parent = first_born;
	}
}


/**
 * get_parent – parent of child node
 * @root: root heap
 * @index: num of current node
 * @pind: index looked for
 *
 * Return: Pointer to heap's node
 */
heap_t *get_parent(heap_t *root, int index, int pind)
{
	heap_t *left = NULL, *right = NULL;

	if (!root || index > pind)
		return (NULL);

	if (index == pind)
		return (root);

	left = get_parent(root->left, index * 2 + 1, pind);
	if (left)
		return (left);

	right = get_parent(root->right, index * 2 + 2, pind);
	if (right)
		return (right);

	return (NULL);
}


/**
 * remove_last_node – pop function removes last node
 * @root: pointer check
 * @parent: last node moved
 */
void remove_last_node(heap_t **root, heap_t *parent)
{
	if (parent == *root && !parent->left)
	{
		free(*root);
		*root = NULL;

		return;
	}

	if (parent->right)
	{
		(*root)->n = parent->right->n;
		free(parent->right);
		parent->right = NULL;
	}
	else if (parent->left)
	{
		(*root)->n = parent->left->n;
		free(parent->left);
		parent->left = NULL;
	}

	bubble_down(*root);
}


/**
 * heap_extract - Extracts the max value of a heap
 * @root: Double pointer to heap's root node
 *
 * Return: Heap's max value
 */
int heap_extract(heap_t **root)
{
	int perfect_node, perfect_index = 0, highest_value = 0;
	heap_t *parent_node;

	if (!root || !(*root))
		return (0);

	highest_value = (*root)->n;
	perfect_index = count_heap_nodes(*root);

	perfect_index = (perfect_index - 2) / 2;
	parent_node = get_parent(*root, 0, perfect_index);

	remove_last_node(root, parent_node);

	return (highest_value);
}

