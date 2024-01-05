#include "binary_trees.h"

/**
 * binary_tree_rotate_left - It performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tmp;

	if (!tree)
		return (NULL);

	if (tree->right)
	{
		tmp = tree->right->left;
		pivot = tree->right;
		pivot->parent = tree->parent;
		pivot->left = tree;
		tree->parent = pivot;
		tree->right = tmp;

		if (tmp)
			tmp->parent = tree;
		return (pivot);
	}
	return (NULL);
}
