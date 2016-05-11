#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "queue.h"

typedef struct queue
{
	char str[]="Hello world!\n";
	queue *tail, *head;
	void push()
	{
		if (next == NULL)
		{
			pid_t pid_temp;
			switch (pid_temp = fork())
			{
				case -1:puts"Error creating child");break;
				case 0:
				if (next = 0)
					queue element;
					element.next = element;
					head = element;
					tail = element;
					element.pid = pid_temp;
				else 
				{
					queue element;
					element.pid = pid_temp;
					element.next = *next;
					head = element;
				}
				break;
			}
		}
	};

	void pop()
	{
		if (head != 0)
			head = head.next;
		else 
			tail = 0;
	};

	void init()
	{	
		tail = 0;
		head = 0;
		next = 0;
		pid = -1;
	};
	
	void destroy()
	{
		while (next != 0)
			pop ();
		pid = -1;
	};
}