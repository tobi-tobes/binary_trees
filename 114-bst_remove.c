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
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: pointer to new node or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

/**
 * duplicate - creates a copy of a node in a binary search tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @min: inorder successor of the node to be deleted
 *
 * Return: the new root node of the tree after removing the desired value
 */
bst_t *duplicate(bst_t *root, bst_t *min)
{
	bst_t *temp;

	temp = binary_tree_node(NULL, min->n);
	temp->parent = root->parent;
	temp->left = root->left;
	temp->right = root->right;

	if (root->left != NULL)
		root->left->parent = temp;

	if (root->right != NULL)
		root->right->parent = temp;

	free(root);
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
			root = duplicate(root, temp);
			root->right = bst_remove(root->right, temp->n);
		}
		return (root);
	}
	return (root);
}
