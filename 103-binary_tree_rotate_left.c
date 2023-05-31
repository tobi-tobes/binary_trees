#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree or NULL
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root, *temp;

	if (tree == NULL)
		return (NULL);

	if (tree->right == NULL)
		return (NULL);

	root = tree->right;
	tree->right = NULL;
	root->parent = NULL;
	tree->parent = root;
	if (root->left == NULL)
		root->left = tree;
	else
	{
		temp = root->left;
		tree->right = temp;
		temp->parent = tree;
		root->left = tree;
	}
	return (root);
}
