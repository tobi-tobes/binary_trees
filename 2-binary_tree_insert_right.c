#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to put in the new node
 *
 * Return: pointer to new node or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *temp;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	if (parent->right == NULL)
	{
		parent->right = new_node;
		new_node->parent = parent;
		new_node->right = NULL;
	}
	else
	{
		temp = parent->right;
		parent->right = new_node;
		new_node->parent = parent;
		new_node->right = temp;
		temp->parent = new_node;
	}
	return (new_node);
}
