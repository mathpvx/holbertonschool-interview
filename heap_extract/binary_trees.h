#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

/**
 * struct queue_s - Queue node for level-order traversal
 *
 * @node: Pointer to the heap node
 * @next: Pointer to the next queue node
 */
typedef struct queue_s
{
	heap_t *node;
	struct queue_s *next;
} queue_t;

/* Function prototypes */
int heap_extract(heap_t **root);
void heapify_down(heap_t *node);
heap_t *get_last_node(heap_t *root);

/* Queue helper functions */
void enqueue(queue_t **head, heap_t *node);
heap_t *dequeue(queue_t **head);

#endif /* BINARY_TREES_H */
