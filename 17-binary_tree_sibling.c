#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: pointer to sibling of node or NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);

	if (node->parent == NULL)
		return (NULL);

	if (node == node->parent->left)
	{
		if (node->parent->right)
			return (node->parent->right);
	}
	else if (node == node->parent->right)
	{
		if (node->parent->left)
			return (node->parent->left);
	}
	return (NULL);
}
