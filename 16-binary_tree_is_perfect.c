#include "binary_trees.h"

/**
 * depth - finds the depth of a tree
 * @tree: pointer to the root node of the tree to check the depth
 *
 * Return: depth of tree
 */
int depth(const binary_tree_t *tree)
{
	int d = 0;
	const binary_tree_t *temp;

	temp = tree;
	while (temp != NULL)
	{
		temp = temp->left;
		d++;
	}
	return (d);
}

/**
 * binary_tree_is_perfect_rec - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * @depth: the depth of the tree
 * @level: the level of the leaf
 *
 * Return: 1 if binary tree is perfect, else 0
 */
int binary_tree_is_perfect_rec(const binary_tree_t *tree, int depth, int level)
{
	if (tree->left == NULL && tree->right == NULL)
	{
		if (depth == level + 1)
			return (1);
		return (0);
	}

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	if (binary_tree_is_perfect_rec(tree->left, depth, level + 1) &&
	    binary_tree_is_perfect_rec(tree->right, depth, level + 1))
		return (1);
	return (0);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if binary tree is perfect, else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	d = depth(tree);
	return (binary_tree_is_perfect_rec(tree, d, 0));
}
