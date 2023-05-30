#include "binary_trees.h"

/**
 * populate - fills an array with pointers to ancestors
 * @tree: pointer to the node to retrieve ancestors
 * @array: array to populate
 * @depth: depth of node
 *
 * Return: nothing
 */
void populate(const binary_tree_t *tree, const binary_tree_t **array,
	      size_t depth)
{
	const binary_tree_t *temp;
	size_t i;

	temp = tree;
	i = depth - 1;
	while (temp != NULL)
	{
		array[i] = temp;
		temp = temp->parent;
		i--;
	}
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to first node
 * @second: pointer to second node
 *
 * Return: pointer to lowest common ancestor or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t d1, d2, i;
	const binary_tree_t **anc_first, **anc_second;
	binary_tree_t *match;
	int found = 0;

	if (first == NULL || second == NULL)
		return (NULL);

	d1 = binary_tree_depth(first) + 1;
	d2 = binary_tree_depth(second) + 1;

	anc_first = malloc(sizeof(binary_tree_t *) * d1);
	anc_second = malloc(sizeof(binary_tree_t *) * d2);
	if (anc_first == NULL || anc_second == NULL)
		return (NULL);

	populate(first, anc_first, d1);
	populate(second, anc_second, d2);

	for (i = 0; i < d1 && i < d2; i++)
	{
		if (anc_first[i]->n == anc_second[i]->n)
		{
			found = 1;
			match = anc_first[i];
		}
	}
	free(anc_first);
	free(anc_second);

	if (found)
		return (match);

	return (NULL);
}
