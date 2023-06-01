#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *
 * Return: pointer to root node or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	if (array == NULL || size <= 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		avl_insert(&root, array[i]);
	}
	return (root);
}
