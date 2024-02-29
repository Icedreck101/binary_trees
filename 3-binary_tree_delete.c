#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree.
 *
 * @tree: Pointer to the root node of the tree to delete.
 *
 * Description: The function deletes an entire binary tree starting at the
 *              given root node. It recursively traverses the tree in
 *              post-order fashion and frees the memory allocated for each node.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
