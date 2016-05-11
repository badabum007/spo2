#include "headers.h"

char _getch()
{
	struct termios old, new;
	char ch;
	tcgetattr(0, &old);
	new = old;
	new.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &new);
	ch = getchar();

	tcsetattr(0, TCSANOW, &old);
	return ch;
}
void createNewProcess(char *path, struct Data *data, struct Stack **stack)
{	
	data->count++;
	switch(data->pid = fork())
	{
		case -1:
			perror("Fork error");
			exit(1);
		case 0:	
		{
			int i = 1, k = data->count / 10;
			for(i = 1; k != 0; i++) 
				k = k / 10;
			char *params;
			params = (char *)malloc((i + 1) * sizeof(char));
			params[i] = '\0';

			for(int num = i, number = data->count; num > 0; num--, number /= 10)
				params[num - 1] = number % 10 + '0';
				
			char *cmd[3] = {path, params, 0};
			execv(path, cmd); 
		}	
		default:
		{
			push(&*stack, *data);
		}
			break;
	}
}

void closeLastProcess(struct Stack **stack, struct Data *data)
{
	semop(data->semid, &(data->mybuff), 1);
	kill((*stack)->pid,SIGKILL);
	pop(&*stack);
	data->count--; 
}

void closeAllProcesses(struct Stack **stack, struct Data *data)
{	
	semop(data->semid, &(data->mybuff), 1);
	semop(data->semid, &(data->mybuff1), 1);
	while(size(*stack) != 0)
	{
		kill((*stack)->pid,SIGKILL);
		pop(stack);
		data->count--;
	}
	return;
}

void createSignalProcess(char *path,struct Data *data)
{
	data->count = 0;

	data->key = ftok(path, 0);
	data->semid = semget(data->key, 1, 0666 | IPC_CREAT);
	semctl(data->semid, 0, SETVAL);
	data->mybuff.sem_num = 0;

	data->mybuff1.sem_num = 0;
 	data->mybuff1.sem_op = 1;
}

void printProcesses(char **argv, struct Data *data)
{
	while(1) 
	{
		semop(data->semid, &(data->mybuff), 1);
		semop(data->semid, &(data->mybuff1), 1);
		usleep(100000);
		printf("Process number: %s\n", argv[1]);
		data->mybuff1.sem_op = -1;
		semop(data->semid, &(data->mybuff1), 1);
		data->mybuff1.sem_op = 1;	
	}
}
