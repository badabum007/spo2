ifeq ($(OS), Windows_NT)

else

СС = gcc
CFLAGS = -Wall -pedantic -c

all: third

third: main lin_stack
	$(CC) -Wall -pedantic -o third main.o lin_stack.o

main: main.c
	$(CC) $(CFLAGS) main.c

lin_stack: lin_stack.c
	$(CC) $(CFLAGS) lin_stack.c

clean:
	rm -rf *.o third

endif