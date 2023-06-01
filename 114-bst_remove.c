#include "binary_trees.h"

/**
 * find_min - searches for the minimum value in the right subtree
 * @root: pointer to the root node of the BST to search
 *
 * Return: pointer to found node or NULL if nothing is found
 */
bst_t *find_min(bst_t *root)
{
	bst_t *temp;

	temp = root;
	while (temp != NULL && temp->left != NULL)
	{
		temp = temp->left;
	}
	return (temp);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Return: the new root node of the tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (root);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			temp = root;
			root = root->right;
			free(temp);
		}
		else if (root->right == NULL)
		{
			temp = root;
			root = root->left;
			free(temp);
		}
		else
		{
			temp = find_min(root->right);
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		}
	}
	return (root);
}
