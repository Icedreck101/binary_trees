#include "binary_trees.h"

/**
 * is_leaf - Checks if a node is a leaf node
 * @node: Pointer to the node to check
 *
 * Return: 1 if @node is a leaf, 0 otherwise
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - Calculates the depth of a node in a binary tree
 * @tree: Pointer to the node to calculate the depth for
 *
 * Return: Depth of the node
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Retrieves a leaf node from the binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: Pointer to a leaf node, or NULL if none is found
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree))
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect recursively
 * @tree: Pointer to the root node of the binary tree
 * @leaf_depth: Depth of the leaf nodes
 * @level: Current level in the tree
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
