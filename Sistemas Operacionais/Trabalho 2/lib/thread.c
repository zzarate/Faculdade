#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <queue.h>
#include <thread.h>

node_t ready_queue;
tcb_t  *current_running;

int tid_global = 0;

/*
  TODO:  thread_init: initializes  the  thread library  and creates  a
  thread for  the main function. Returns  0 on success, or  -EINVAL if
  the library has already been initialized.
 */
int thread_init()
{
	if (ready_queue.key)
	{
		return -EINVAL;
	}

	tcb_t *new_tcb = (tcb_t *) malloc(sizeof(tcb_t));
	node_t *main_thread;

	queue_init(main_thread);

	main_thread->key = new_tcb;
	current_running = main_thread->key;
	return 0;
}

// TODO: creates a new thread and inserts in the ready queue.
int thread_create(thread_t *thread, void *(*start_routine)(void *), void *arg)
{
	tcb_t *new_tcb = (tcb_t *) malloc(sizeof(tcb_t));
	node_t *new_node = (node_t *) malloc(sizeof(node_t));
	new_tcb->stack = malloc(STACK_SIZE); //Alocar em byte

	new_tcb->sp = new_tcb->stack + STACK_SIZE - 1;
	new_tcb->status = READY;

	new_node->key = new_tcb;

	enqueue(&ready_queue, new_node);

	return 0;
}

// TODO: yields the CPU to another thread
int thread_yield()
{
	// Chamar a função scheduler_entry do entry.S
	return 0;
}

// TODO: waits for a thread to finish
int thread_join(thread_t *thread, int *retval)
{
	tcb_t *tcb;
	tcb = thread->tcb;

	if (tcb->status == EXITED)
		return 0;
	
	
}

// TODO: marks a thread as EXITED and terminates the thread
void thread_exit(int status)
{
}

// TODO: selects the next thread to execute
void scheduler()
{
	node_t *queue;
	queue = dequeue(&ready_queue);
	
	if (queue != NULL) {
		current_running = queue->key;
	}
}

// TODO: you must  make sure this function is called  if a thread does
// not call thread_exit
void exit_handler()
{
}
