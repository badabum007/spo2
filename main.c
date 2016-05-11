#include "headers.h"

int main(int argc, char *argv[])
{
	struct Stack *stack = NULL;
	struct Data data;
	if (argc == 1)
	{
		createSignalProcess(argv[0], &data);

		while (1)
		{
			switch (_getch())
			{
			case '+':
				createNewProcess(argv[0], &data, &stack);
				break;
			case '-':
				if (size(stack) != 0)
					closeLastProcess(&stack, &data);
				break;
			case 'q':
				closeAllProcesses(&stack, &data);
				return 0;
				break;
			}
		}
	}
	else
		printProcesses(argv, &data);

	return 0;
}
