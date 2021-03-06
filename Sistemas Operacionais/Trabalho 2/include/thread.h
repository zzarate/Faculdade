#ifndef THREAD_H
#define THREAD_H

#include <stdint.h>
#include <threadu.h>

#define NUMBER_OF_REGISTERS	15
#define STACK_SIZE		2048

void scheduler_entry();
void exit_handler();

typedef enum {
	      FIRST_TIME, // Não é relevante
	      READY,
	      BLOCKED,
	      EXITED
} status_t;

typedef struct tcb {
	uint64_t regs[NUMBER_OF_REGISTERS];
	uint64_t flag;

	void *stack;
	void *sp; //Apotar para final da pilha
	status_t status;
} tcb_t;

#endif /* THREAD_H */
