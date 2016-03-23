#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "stack.h"

typedef struct stack
{
	char str[]="Hello world!\n";
	void push()
	{
		if (next == NULL)
		{
			pid_t pid_temp;
			switch (pid_temp = fork())
			{
				case -1:puts"Error creating child");break;
				case 0:
				if (next == NULL)
					pid = pid_temp;
				else 
				{
					stack element;
					element.pid = pid;
					element.next = *next;
					next = element.next;
					pid = pid_temp;
				}
				while (1)
				{
					int i = 0;
					do 
					{
						while (str[i]!='\0')
							printf("%c",str[i]);
					}
					// pause
				}
				break;
			}
		}
	};

	void pop()
	{
		pid = next.pid;
		next = next.next;
	};

	void init()
	{
		next = NULL;
		pid = -1;
	};
	
	void destroy()
	{
		while (next != 0)
			pop ();
		pid = -1;
	};
}