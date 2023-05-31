#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: the size of the tree or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right)
		+ 1);
}

/**
 * binary_tree_is_complete_rec - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @index: index of node
 * @count: number of nodes in tree
 *
 * Return: 1 if complete and 0 if not complete
 */
int binary_tree_is_complete_rec(const binary_tree_t *tree, size_t index,
				size_t count)
{
	if (tree == NULL)
		return (1);

	if (index >= count)
		return (0);

	if (binary_tree_is_complete_rec(tree->left, (2 * index) + 1, count)
	    &&
	    binary_tree_is_complete_rec(tree->right, (2 * index) + 2, count))
		return (1);

	return (0);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if complete and 0 if not complete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t count;

	if (tree == NULL)
		return (0);

	count = binary_tree_size(tree);
	return (binary_tree_is_complete_rec(tree, 0, count));
}
