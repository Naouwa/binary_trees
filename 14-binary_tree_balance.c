#include "binary_trees.h"

/**
 * binary_tree_height - measures height of binary tree
 * @tree: pointer to root node of tree
 *
 * Return: height or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftheight = 0;
	size_t rightheight = 0;

	if (tree)
	{
		if (tree->left != NULL)
			leftheight = binary_tree_height(tree->left) + 1;
		else
			leftheight = 1;
		if (tree->right != NULL)
			rightheight = binary_tree_height(tree->right) + 1;
		else
			rightheight = 1;
		if (leftheight > rightheight)
			return (leftheight);
		else
			return (rightheight);
	}
	return (0);
}

/**
 * binary_tree_balance - measure balance factor of binary tree
 * @tree: pointer to root node of the binary tree
 *
 * Return: balance factor or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	return (0);
}
