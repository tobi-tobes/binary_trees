#include "binary_trees.h"

/**
 * bst_insert_rec - inserts a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to inserted node or NULL if value already exists
 */
bst_t *bst_insert_rec(bst_t *tree, int value)
{
	if (value < tree->n)
	{
		if (tree->left == NULL)
		{
			tree->left = binary_tree_node(tree, value);
			return (tree->left);
		}
		return (bst_insert_rec(tree->left, value));
	}
	if (value > tree->n)
	{
		if (tree->right == NULL)
		{
			tree->right = binary_tree_node(tree, value);
			return (tree->right);
		}
		return (bst_insert_rec(tree->right, value));
	}
	return (NULL);
}

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to inserted node or NULL if value already exists
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}
	return (bst_insert_rec(*tree, value));
}

/**
 * check_balance - checks the balance factor of an AVL Tree
 * @node: pointer to node to start backtracking from.
 *
 * Return: pointer to the node that is imbalanced or NULL if tree is balanced
 */
avl_t *check_balance(avl_t *node)
{
	avl_t *temp;
	int balance_factor;

	temp = node;
	while (temp != NULL)
	{
		balance_factor = binary_tree_balance((const avl_t *)temp);
		if (abs(balance_factor) > 1)
			return (temp);
		temp = temp->parent;
	}
	return (NULL);
}

/**
 * fix_imbalance - rebalances an AVL Tree
 * @imbalanced: pointer to the imbalanced node of the AVL Tree
 *
 * Return: pointer to balanced tree
 */
avl_t *fix_imbalance(avl_t *imbalanced)
{
	int balance_factor, previous;
	avl_t *parent, *root;
	const avl_t *temp;

	parent = imbalanced->parent;
	previous = imbalanced->n;
	temp = (const avl_t *)imbalanced;
	balance_factor = binary_tree_balance(temp);
	if (balance_factor > 1)
	{
		if (binary_tree_balance(temp->left) == -1)
		{
			imbalanced->left = binary_tree_rotate_left
				(imbalanced->left);
			imbalanced->left->parent = imbalanced;
		}
		imbalanced = binary_tree_rotate_right(imbalanced);
	}
	else if (balance_factor < -1)
	{
		if (binary_tree_balance(temp->right) == 1)
		{
			imbalanced->right = binary_tree_rotate_right
				(imbalanced->right);
			imbalanced->right->parent = imbalanced;
		}
		imbalanced = binary_tree_rotate_left(imbalanced);
	}
	imbalanced->parent = parent;
	if (parent->left->n == previous)
		parent->left = imbalanced;
	else
		parent->right = imbalanced;
	root = imbalanced;
	while (root->parent != NULL)
		root = root->parent;
	return (root);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to inserted node or NULL on failure or
 * if value already exists
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node, *imbalanced;

	if (tree == NULL)
		return (NULL);

	node = bst_insert(tree, value);
	imbalanced = check_balance(node);
	if (imbalanced == NULL)
		return (node);

	*tree = fix_imbalance(imbalanced);
	return (node);
}
