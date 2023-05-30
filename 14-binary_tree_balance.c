#include "binary_trees.h"

/**
 * height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: the height of the tree or 0 if tree is NULL
 */
size_t height(const binary_tree_t *tree)
{
	size_t lheight, rheight;

	if (tree == NULL)
		return (0);

	lheight = 1 + binary_tree_height(tree->left);
	rheight = 1 + binary_tree_height(tree->right);

	if (lheight > rheight)
		return (lheight);
	else
		return (rheight);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor.
 *
 * Return: the balance factor of the tree or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t lheight, rheight;

	if (tree == NULL)
		return (0);

	lheight = height(tree->left);
	rheight = height(tree->right);
	return (lheight - rheight);
}
