#include "binary_trees.h"

/**
 * binary_tree_rotate_right - It performs a right rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tmp;

	if (!tree)
		return (NULL);

	if (tree->left)
	{
		tmp = tree->left->right;
		pivot = tree->left;
		pivot->parent = tree->parent;
		pivot->right = tree;
		tree->parent = pivot;
		tree->left = tmp;

		if (tmp)
			tmp->parent = tree;
		return (pivot);
	}
	return (NULL);
}
