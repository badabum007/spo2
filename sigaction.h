#ifndef SIG_STRUCT_H
#define SIG_STRUCT_H

#include <signal.h>

struct sigaction 
{
	void      (*sa_handler)(int);
	sigset_t sa_mask;
	int      sa_flags;
	void     (*sa_sigaction)(int, siginfo_t *, void *);
};

#endif