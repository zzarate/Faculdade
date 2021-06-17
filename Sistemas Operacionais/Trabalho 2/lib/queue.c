#include <queue.h>

/*
  This   file    contains   a    function   definitions    for   queue
  manipulation. You  are free to  choose your own  implementation. You
  may need to define additional functions if you want to implement the
  extra-point functionality.
 */

void queue_init(node_t *queue)
{
	node_t *new_node;

	new_node = (node_t *) malloc(sizeof(node_t));
	new_node->next = NULL;
	queue = new_node;
}

// returns the first element of the queue
node_t *dequeue(node_t *queue)
{
	/* Sanitize */
	if(!queue)
		return NULL;

	if (queue->next != NULL) {
		node_t *n;
		n = queue;

		queue = n->next;

		free(n);
		return queue;
	} else if (queue) {
		free(queue);
	}
	return NULL;
}

// inserts a node in a queue
void enqueue(node_t *queue, node_t *item)
{
	node_t *n;

	/* Sanitize */
	if (!queue)
		return;
	if	(!item)
		return;

	for (n = queue; n->next != NULL ; n = n->next);

	if (n->next = NULL)
		n->next = item;

	return;
}

// checks if a queue is empty
int is_empty(node_t *queue)
{
	if(!queue)
		return 1;

	return 0;
}



