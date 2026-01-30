/* 1-heap_insert.c */
#include "binary_trees.h"

#include <stdlib.h>

/**
 * heap_size - count nodes in a heap
 * @root: pointer to root
 *
 * Return: number of nodes
 */
static size_t heap_size(const heap_t *root)
{
	if (!root)
		return (0);

	return (1 + heap_size(root->left) + heap_size(root->right));
}

/**
 * node_at_index - get node at given 1-based index in level-order (like array heap)
 * @root: pointer to root
 * @idx: 1-based index
 *
 * Return: pointer to node, or NULL
 */
static heap_t *node_at_index(heap_t *root, size_t idx)
{
	size_t path[64];
	int top;
	size_t n;

	if (!root || idx == 0)
		return (NULL);

	top = 0;
	n = idx;
	while (n > 1)
	{
		path[top++] = n;
		n /= 2;
	}

	while (top > 0 && root)
	{
		size_t cur = path[--top];

		if (cur % 2 == 0)
			root = root->left;
		else
			root = root->right;
	}
	return (root);
}

/**
 * heapify_up - restore max-heap property by swapping values upward
 * @node: node to heapify from
 *
 * Return: pointer to node after heapify (the inserted node position by value)
 */
static heap_t *heapify_up(heap_t *node)
{
	while (node && node->parent && node->n > node->parent->n)
	{
		int tmp = node->n;

		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - insert a value into a Max Binary Heap
 * @root: double pointer to root node
 * @value: value to insert
 *
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t sz, idx;
	heap_t *parent, *newn;

	if (!root)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	sz = heap_size(*root);
	idx = sz + 1;

	parent = node_at_index(*root, idx / 2);
	if (!parent)
		return (NULL);

	newn = binary_tree_node(parent, value);
	if (!newn)
		return (NULL);

	if (idx % 2 == 0)
		parent->left = newn;
	else
		parent->right = newn;

	heapify_up(newn);
	return (newn);
}
