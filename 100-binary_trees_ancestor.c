#include "binary_trees.h"

size_t _tree_depth(const binary_tree_t *node);
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to first node
 * @second: pointer to second node
 *
 * Return: pointer to lowest common ancestor, otherwise NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	size_t first_depth, second_depth;
	binary_tree_t *ancestor1 =  (binary_tree_t *)first;
	binary_tree_t *ancestor2 = (binary_tree_t *)second;

	if (!ancestor1 || !ancestor2)
		return (NULL);
	first_depth = _tree_depth(ancestor1);
	second_depth = _tree_depth(ancestor2);

	if (first_depth > second_depth)
	{
		while (first_depth > second_depth)
		{
			ancestor1 = ancestor1->parent;
			first_depth--;
		}
	}
	if (second_depth > first_depth)
	{
		while (second_depth > first_depth)
		{
			ancestor2 = ancestor2->parent;
			second_depth--;
		}
	}
	while (ancestor1 != ancestor2)
	{
		ancestor1 = ancestor1->parent;
		ancestor2 = ancestor2->parent;
	}
	return (ancestor1);
}

/**
 * _tree_depth - depth of node in tree
 * @node: pointer to node
 *
 * Return: depth in size_t type
 */
size_t _tree_depth(const binary_tree_t *node)
{
	size_t result;

	if (node == NULL || node->parent == NULL)
		return (0);
	result = _tree_depth(node->parent);
	result += 1;
	return (result);
}
