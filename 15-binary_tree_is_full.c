#include "binary_trees.h"

/**
 * is_full_recursive - Checks if a binary tree is full recursively
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int is_full_recursive(const binary_tree_t *tree)
{
	if (tree)
	{
		if ((tree->left && !tree->right) ||
		    (!tree->left && tree->right) ||
		    !is_full_recursive(tree->left) ||
		    !is_full_recursive(tree->right))
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_full_recursive(tree));
}
