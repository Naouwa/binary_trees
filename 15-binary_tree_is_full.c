#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if binary tree is full
 * @tree: pointer to the root node of the binary tree
 *
 * Return: 1 if binary tree is full, otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree)
	{
		if (!tree->left && !tree->right)
			return (1);
		if (!tree->left || !tree->right)
			return (0);
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	}
	return (1);
}
