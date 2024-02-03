#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: tree to delete
 * Description: Deletes each node in the binary tree recursively,
 * freeing its memory
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
	return;
	binary_tree_delete(tree->right);
	binary_tree_delete(tree->left);
	free(tree);
}
