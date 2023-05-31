#include "binary_trees.h"

/**
 * bst_insert_rec - inserts a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to inserted node or NULL on failure
 */
bst_t *bst_insert_rec(bst_t *tree, int value)
{
	if (value < tree->n)
	{
		if (tree->left == NULL)
		{
			tree->left = binary_tree_node(tree, value);
			return (tree->left);
		}
		return (bst_insert_rec(tree->left, value));
	}
	if (value > tree->n)
	{
		if (tree->right == NULL)
		{
			tree->right = binary_tree_node(tree, value);
			return (tree->right);
		}
		return (bst_insert_rec(tree->right, value));
	}
	return (NULL);
}

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to inserted node or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}
	return (bst_insert_rec(*tree, value));
}
