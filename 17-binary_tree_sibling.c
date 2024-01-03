#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: pointer to the sibling node, NULL otherwise
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling;

	if (node && node->parent && node->parent->left && node->parent->right)
	{
		if (node->parent->left != node)
		{
			sibling = node->parent->left;
			return (sibling);
		}
		if (node->parent->right != node)
		{
			sibling = node->parent->right;
			return (sibling);
		}
	}
	return (NULL);
}
