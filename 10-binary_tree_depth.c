#include "binary_trees.h"

/**
 * binary_tree_depth - It measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 *
 * Return: 0
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	for (depth = 0; tree->parent; depth++)
		tree = tree->parent;

	return (depth);
	/* I got a segmenttation fault, and no code works for me :'( */
}
