#ifndef _HEADER_
#define _HEADER_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
size_t height(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int depth(const binary_tree_t *tree);
int binary_tree_is_perfect_rec(const binary_tree_t *tree, int depth,
			       int level);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
void populate(const binary_tree_t *tree, const binary_tree_t **array,
	      size_t depth);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second);
void binary_tree_levelorder_level(const binary_tree_t *tree,
				  void (*func)(int), size_t level);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_complete_rec(const binary_tree_t *tree, size_t index,
				size_t count);
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int max_value(const binary_tree_t *tree);
int min_value(const binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
int binary_tree_is_bst_rec(const binary_tree_t *tree, int min, int max);
bst_t *bst_insert_rec(bst_t *tree, int value);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *find_min(bst_t *root);
bst_t *duplicate(bst_t *root, bst_t *min);
bst_t *bst_remove(bst_t *root, int value);
int binary_tree_is_avl_rec(const binary_tree_t *tree);
int binary_tree_is_avl(const binary_tree_t *tree);
avl_t *check_balance(avl_t *node);
avl_t *fix_imbalance(avl_t *imbalanced);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);

#endif
