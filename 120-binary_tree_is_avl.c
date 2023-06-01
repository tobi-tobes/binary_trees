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
 * max_value - finds the maximum value of a subtree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: maximum value of a subtree
 */
int max_value(const binary_tree_t *tree)
{
	int value, left_max, right_max;

	if (tree == NULL)
		return (INT_MIN);

	left_max = max_value(tree->left);
	right_max = max_value(tree->right);

	if (left_max > right_max)
		value = left_max;
	else
		value = right_max;

	if (value < tree->n)
		value = tree->n;

	return (value);
}

/**
 * min_value - finds the minimum value of a subtree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: minimum value of a subtree
 */
int min_value(const binary_tree_t *tree)
{
	int value, left_min, right_min;

	if (tree == NULL)
		return (INT_MAX);

	left_min = min_value(tree->left);
	right_min = min_value(tree->right);

	if (left_min < right_min)
		value = left_min;
	else
		value = right_min;

	if (value > tree->n)
		value = tree->n;

	return (value);
}

/**
 * binary_tree_is_bst_rec - checks if a binary tree is a valid BST
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST or 0
 */
int binary_tree_is_bst_rec(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left && max_value(tree->left) > tree->n)
		return (0);

	if (tree->right && min_value(tree->right) < tree->n)
		return (0);

	return (binary_tree_is_bst_rec(tree->left) &&
		binary_tree_is_bst_rec(tree->right));
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

	return (binary_tree_is_bst_rec(tree));
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
