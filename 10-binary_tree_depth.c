#include "binary_trees.h"

/**
 * binary_tree_depth - Measure the depth of a node in a binary tree.
 *
 * @tree: Pointer to the node to measure.
 *
 * Return: Depth of the node, or 0 if `tree` is NULL or has no parent.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
