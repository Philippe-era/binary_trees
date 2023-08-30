#include "binary_trees.h"

bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);
bst_t *inorder_successor(bst_t *root);


/**
 * inorder_successor – the lowest of the BST search to be evulated
 * @root: pointer of the root
 *
 * Return: lowest value of binary tree
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete – node to be castrated
 * @root: root to BST pointed
 * @node: deleted node
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent_node_created = node->parent, *inherited = NULL;

	/* No sibling of the parent */
	if (node->left == NULL)
	{
		if (parent_node_created != NULL && parent_node_created->left == node)
			parent_node_created->left = node->right;
		else if (parent_node_created != NULL)
			parent_node_created->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent_node_created;
		free(node);
		return (parent_node_created == NULL ? node->right : root);
	}

	/* Left sibling will be checked onmly */
	if (node->right == NULL)
	{
		if (parent_node_created != NULL && parent_node_created->left == node)
			parent_node_created->left = node->left;
		else if (parent_node_created != NULL)
			parent_node_created->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent_node_created;
		free(node);
		return (parent_node_created == NULL ? node->left : root);
	}

	/* The number of siblings are 2 */
	inherited = inorder_successor(node->right);
	node->n = inherited->n;

	return (bst_delete(root, inherited));
}

/**
 * bst_remove_recursive – node removed recursively from the bst
 * @root: root to be casrated
 * @node: current node to be checked
 * @value: value to be removed from list
 *
 * Return: after pointer to be executed
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove – the node will be removed from the list
 * @root: root will be removed
 * @value: the castrated value form bst
 * Return: new pointer to be createds
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}

