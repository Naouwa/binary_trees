#include "binary_trees.h"

/**
 * binary_tree_uncle - finds uncle of a node
 * @node: pointer to the node to find the uncle
 *
 * Return: pointer to uncle node, otherwise NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle;

	if (node && node->parent && node->parent->parent)
	{
		if (node->parent->parent->left != node->parent)
		{
			uncle = node->parent->parent->left;
			return (uncle);
		}
		if (node->parent->parent->right != node->parent)
		{
			uncle = node->parent->parent->right;
			return (uncle);
		}
	}
	return (NULL);
}
