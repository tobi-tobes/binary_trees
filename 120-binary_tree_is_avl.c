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

	lheight = 1 + height(tree->left);
	rheight = 1 + height(tree->right);

	if (lheight > rheight)
		return (lheight);
	else
		return (rheight);
}

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

/**
 * binary_tree_is_avl_rec - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl_rec(const binary_tree_t *tree)
{
	int balance, lheight, rheight;

	if (tree == NULL)
		return (1);

	if (!binary_tree_is_bst(tree))
		return (0);

	lheight = height(tree->left);
	rheight = height(tree->right);
	balance = lheight - rheight;
	if (abs(balance) <= 1 && binary_tree_is_avl_rec(tree->left)
	    && binary_tree_is_avl_rec(tree->right))
		return (1);

	return (0);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_avl_rec(tree));
}
