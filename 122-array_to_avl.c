#include "binary_trees.h"

/**
 * array_to_avl – construction of array using avl
 * @array: element to be converted
 * @size: array count
 *
 * Return: pointer to node
*/
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *new_tree = NULL;
	size_t initial, join;

	if (array == NULL)
		return (NULL);

	for (initial = 0; initial < size; initial++)
	{
		for (join = 0; join < initial; join++)
		{
			if (array[join] == array[initial])
				break;
		}
		if (join == initial)
		{
			if (avl_insert(&new_tree, array[initial]) == NULL)
				return (NULL);
		}
	}

	return (new_tree);
}

