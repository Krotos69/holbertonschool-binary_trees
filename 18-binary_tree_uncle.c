#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 *
 * Return: pointer to the uncle node, or NULL if no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)

{
binary_tree_t *parent, *grandparent;

if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
return (NULL);

parent = node->parent;
grandparent = parent->parent;

if (grandparent->left == parent)
return (grandparent->right);

if (grandparent->right == parent)
return (grandparent->left);

return (NULL);
}
