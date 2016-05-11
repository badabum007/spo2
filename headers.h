#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

#define PLATFORM_WIN 1 
#define PLATFORM_UNIX 2 

#if defined(_WIN32) || defined(_WIN64) 
	#include <windows.h> 
	#include <conio.h> 
	#define PLATFORM PLATFORM_WIN 
#else 
	#include <sys/sem.h>
	#include <sys/types.h>
	#include <sys/wait.h>
	#include <errno.h>
	#include <unistd.h>
	#include <termios.h>
	#define PLATFORM PLATFORM_UNIX 

char _getch();
#endif 

struct Data 
{
	#if PLATFORM == PLATFORM_WIN
	PROCESS_INFORMATION prInfo;
	#else
	pid_t pid;	
	key_t key;
	int semid;
	struct sembuf mybuff, mybuff1;
	#endif
	int count;
};

#include "stack.h"

void CreateNewProcess(char *, struct Data *, struct Stack **);
void CloseLastProcess(struct Stack **, struct Data *);
void CloseAllProcesses(struct Stack **, struct Data *);

void CreateSignalProcess(struct Data *);
void PrintProcesses(char **argv, struct Data *);