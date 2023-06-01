#include "binary_trees.h"

/**
 * binary_tree_is_bst_rec - checks if a binary tree is a valid BST
 * @tree: pointer to the root node of the tree to check
 * @min: minimum number to compare node to
 * @max: maximum number to compare node to
 *
 * Return: 1 if tree is a valid BST or 0
 */
int binary_tree_is_bst_rec(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (binary_tree_is_bst_rec(tree->left, min, tree->n) &&
		binary_tree_is_bst_rec(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST or 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_bst_rec(tree, INT_MIN, INT_MAX));
}
