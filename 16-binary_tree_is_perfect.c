#include "binary_trees.h"


int _is_leaf(const binary_tree_t *node);
int _tree_height(const binary_tree_t *tree);
int _is_parent(const binary_tree_t *node);

/**
 * binary_tree_is_perfect - checks if binary tree is perfect
 * @tree: pointer to root node of binary tree
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (_tree_height(tree->left) == _tree_height(tree->right))
	{
		if (_tree_height(tree->left) == -1)
			return (1);
		if (_is_leaf(tree->left) && _is_leaf(tree->right))
			return (1);
		if (_is_parent(tree))
			return (binary_tree_is_perfect(tree->left)
					&& binary_tree_is_perfect(tree->right));
	}
	return (0);
}

/**
 * _is_leaf - Checks if node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, otherwise 0
 */
int _is_leaf(const binary_tree_t *node)
{
	if (node && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * _tree_height - It measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: height of tree
 */
int _tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (-1);
	left = _tree_height(tree->left);
	right = _tree_height(tree->right);

	return ((left > right) ? (left + 1) : (right + 1));
}

/**
 * _is_parent - checks if node is parent
 * @node: pointr to node to check
 *
 * Return: 1 if parent, 0 otherwise
 */
int _is_parent(const binary_tree_t *node)
{
	if (node && node->left && node->right)
		return (1);
	return (0);
}

