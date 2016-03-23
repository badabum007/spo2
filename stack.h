#ifndef STACK_H
#define STACK_H

typedef struct stack
{
	#if PLATFORM == PLATFORM_WIN
		#include <windows.h>
		HANDLE hand;
	#else
		#include <unistd.h>
		#include <sys/types.h>
		pid_t pid;
	#endif

	stack* next;

	void push();
	void pop();
	void init();
	void destroy();
};

#endif