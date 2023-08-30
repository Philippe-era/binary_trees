#include "binary_trees.h"
void pop(levelorder_queue_t **head);
levelorder_queue_t *create_node(binary_tree_t *node);
int binary_tree_is_complete(const binary_tree_t *tree);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);


/**
 * create_node – new levelorder created
 * @node: binary tree to be created
 *
 * Return: null is an error
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_queue;

	new_queue = malloc(sizeof(levelorder_queue_t));
	if (new_queue == NULL)
		return (NULL);

	new_queue->node = node;
	new_queue->next = NULL;

	return (new_queue);
}

/**
 * free_queue – Empties the que of the levelorder
 * @head: head of the queue pointed
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temporary;

	while (head != NULL)
	{
		temporary = head->next;
		free(head);
		head = temporary;
	}
}


/**
 * pop – removes first node in queue
 * @head: double header pointer
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temporary;

	temporary = (*head)->next;
	free(*head);
	*head = temporary;
}

/**
 * push – Pushes it to the end of the line
 * @node: shows the node
 * @head: first node
 * @tail: last node
 */

void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new_queue;

	new_queue = create_node(node);
	if (new_queue == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new_queue;
	*tail = new_queue;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: pointer to the node
 * Return: if tree is null it is not valid
 * Description: Upon malloc failure, exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char pattern = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (pattern == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			pattern = 1;
		if (head->node->right != NULL)
		{
			if (pattern == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			pattern = 1;
		pop(&head);
	}
	return (1);
}

