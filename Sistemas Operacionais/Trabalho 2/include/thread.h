#ifndef THREAD_H
#define THREAD_H

#include <stdint.h>
#include <threadu.h>

#define NUMBER_OF_REGISTERS	15
#define STACK_SIZE		2048

void scheduler_entry();
void exit_handler();

typedef enum {
	      FIRST_TIME,
	      READY,
	      BLOCKED,
	      EXITED
} status_t;

typedef struct tcb {
	// TODO: define the fields for you TCB
	uint64_t regs[NUMBER_OF_REGISTERS];
	uint64_t flag;

	status_t status;
} tcb_t;

#endif /* THREAD_H */
