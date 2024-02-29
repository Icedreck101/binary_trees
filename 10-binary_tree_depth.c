#include "binary_trees.h"

/**
 * binary_tree_depth - Measure the depth of a node in a binary tree.
 *
 * @tree: Pointer to the node to measure.
 *
 * Description: This function measures the depth of a given node in a binary tree,
 *              which is defined as the number of edges between the node and the tree's root.
 *
 * Return: Depth of the node, or 0 if `tree` is NULL or has no parent.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    /* If tree is NULL or has no parent, return 0 */
    if (tree == NULL || tree->parent == NULL)
        return (0);

    /* Recursively calculate the depth of the parent node */
    return (1 + binary_tree_depth(tree->parent));
}
