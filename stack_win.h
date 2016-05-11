#include <stdio.h>
#include <windows.h>
#include "stack.h"

void print()
{
	HANDLE Event = OpenEvent(EVENT_ALL_ACCESS, FALSE, "MyEvent");
	while (1)
	{
		WaitForSingleObject(Event, INFINITE);
		printf("I am a process number %d\n", count);
		SetEvent(Event);
		Sleep(100);
	}
}

void pop()
{
	if (head != 0)
		head = head.next;
	else 
		tail = 0;
}

void init()
{	
	head = 0;
	next = 0;
	hand = 0;
}

void destroy()
{
	while (next != 0)
		pop ();
	pid = 0;
}

void push() 
{
	struct Stack *tmp = (struct Stack *)malloc(sizeof(struct Stack));
	if (tmp == NULL)
	{
		puts("Stack element creation error");
		exit(1);
	}
	tmp->next = next;
	tmp->hand = data.prInfo.hProcess;
	*head = tmp;
}





int size(const struct Stack *head) {

	int size = 0;
	while (head) {
		size++;
		head = head->next;
	}

	return size;
}

void push(struct Stack **head, struct Data data) {

	struct Stack *tmp = (struct Stack *)malloc(sizeof(struct Stack));
	if (tmp == NULL)
		exit(1);

	tmp->next = *head;
	tmp->hand = data.prInfo.hProcess;

	*head = tmp;
}

void pop(struct Stack **head) {

	struct Stack *out;

	if (*head == NULL)
		exit(1);

	out = *head;
	*head = (*head)->next;
	
	free(out);
}