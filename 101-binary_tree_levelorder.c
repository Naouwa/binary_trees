#include "binary_trees.h"

size_t _tree_size(const binary_tree_t *tree);
/**
 * binary_tree_levelorder - goes through binary tree using level-order traversal
 * @tree: pointer to root node of the tree
 * @func: pointer to function to call for each node
 *
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **stock;
	binary_tree_t *current = (binary_tree_t *)tree;
	binary_tree_t *sibling = NULL;
	unsigned int index = 0;
	size_t size = _tree_size(tree);


	if (tree && func)
	{
		stock = malloc(sizeof(binary_tree_t *) * size + 1);
		if (stock == NULL)
			return;
		while (index < size)
		{
			stock[index] = current;
			func(current->n);

			if (sibling)
			{
				stock[index++] = sibling;
				func(sibling->n);
				if (sibling == current->parent->right && !sibling->left && !sibling->right)
					current = sibling->parent->parent->right;

			}

			if (current->left)
			{
				if (current->right)
					sibling = current->right;
				current = current->left;
			}
			index++;
		}
	}
	free(stock);
}

/**
 * _tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: size of the tree or 0 if tree is NULL
 */
size_t _tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	else
	{
		size += 1;
		size += _tree_size(tree->left);
		size += _tree_size(tree->right);
	}
	return (size);
}
