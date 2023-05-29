#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: the height of the tree or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lheight, rheight;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	lheight = 1 + binary_tree_height(tree->left);
	rheight = 1 + binary_tree_height(tree->right);

	if (lheight > rheight)
		return (lheight);
	else
		return (rheight);
}
