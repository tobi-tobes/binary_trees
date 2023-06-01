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
 * binary_tree_levelorder_level - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * @level: level of the node
 *
 * Return: nothing
 */
void binary_tree_levelorder_level(const binary_tree_t *tree, void (*func)(int),
				  size_t level)
{
	if (tree == NULL)
		return;

	if (level == 0)
		func(tree->n);
	else
	{
		binary_tree_levelorder_level(tree->left, func, level - 1);
		binary_tree_levelorder_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree) * 2;
	for (i = 0; i < height; i++)
	{
		binary_tree_levelorder_level(tree, func, i);
	}
}
