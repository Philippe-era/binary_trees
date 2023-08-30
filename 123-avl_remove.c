#include "binary_trees.h"

/**
 * bal – balance factor of AVL measured
 * @tree: evulated tree
 * Return: balance factor in measurement
 */
void bal(avl_t **tree)
{
	int binary_value;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	binary_value = binary_tree_balance((const binary_tree_t *)*tree);
	if (binary_value > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (binary_value < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor – the next in line
 * @node: tree to check and anlyze
 * Return: minimum value
 */
int successor(bst_t *node)
{
	int left_sibling = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left_sibling = successor(node->left);
		if (left_sibling == 0)
		{
			return (node->n);
		}
		return (left_sibling);
	}

}
/**
 *remove_type – removes the sibling from binary
 *@root: remove the node from the list
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *root)
{
	int value_created = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		value_created = successor(root->right);
		root->n = value_created;
		return (value_created);
	}
}
/**
 * bst_remove – BST tree removes a node
 * @root: The tree node tree
 * @value: value created
 * Return: the new change
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int binary_type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		binary_type = remove_type(root);
		if (binary_type != 0)
			bst_remove(root->right, binary_type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove – AVL TREE to be checke
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *new_root_formed = (avl_t *) bst_remove((bst_t *) root, value);

	if (new_root_formed == NULL)
		return (NULL);
	bal(&new_root_formed);
	return (new_root_formed);
}





