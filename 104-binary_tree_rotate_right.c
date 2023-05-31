#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree or NULL
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root, *temp;

	if (tree == NULL)
		return (NULL);

	if (tree->left == NULL)
		return (NULL);

	root = tree->left;
	tree->left = NULL;
	root->parent = NULL;
	tree->parent = root;
	if (root->right == NULL)
		root->right = tree;
	else
	{
		temp = root->right;
		tree->left = temp;
		temp->parent = tree;
		root->right = tree;
	}
	return (root);
}
