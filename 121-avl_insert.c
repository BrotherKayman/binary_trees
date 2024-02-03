#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: A pointer to the created node
 *         NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp = *tree;
	bst_t *second = NULL;
	bst_t *new = binary_tree_node(NULL, value);

	if (*tree == NULL)
		*tree = new;

	while (tmp)
	{
		second = tmp;
		if (value < tmp->n)
			tmp = tmp->left;
		else if (value > tmp->n)
			tmp = tmp->right;
		else if (value == tmp->n)
			return (NULL);
	}

	if (second == NULL)
		second = new;
	else if (value < second->n)
	{
		second->left = new;
		new->parent = second;
	}
	else
	{
		second->right = new;
		new->parent = second;
	}

	return (new);
}

/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to be inserted
 *
 * Return: Pointer to the created node or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (tree == NULL)
        return (NULL);

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        if (*tree == NULL)
            return NULL;
        return (*tree);
    }

    if (value < (*tree)->n)
    {
        (*tree)->left = avl_insert(&((*tree)->left), value);
        if ((*tree)->left == NULL)
            return (NULL);
    }
    else if (value > (*tree)->n)
    {
        (*tree)->right = avl_insert(&((*tree)->right), value);
        if ((*tree)->right == NULL)
            return (NULL);
    }
    else
        return (NULL);

    (*tree)->height = 1 + MAX(avl_height((*tree)->left), avl_height((*tree)->right));
    int balance = avl_balance_factor(*tree);

    if (balance > 1 && value < (*tree)->left->n)
        return (avl_right_rotate(*tree));

    if (balance < -1 && value > (*tree)->right->n)
        return (avl_left_rotate(*tree));

    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = avl_left_rotate((*tree)->left);
        return (avl_right_rotate(*tree));
    }

    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = avl_right_rotate((*tree)->right);
        return avl_left_rotate(*tree);
    }

    return *tree;
}

