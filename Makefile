CC = gcc
CFLAGS = -c -Wall -pedantic
STAND:=  -std=gnu99

ifeq ($(OS), Windows_NT)

all: output

output: laba_win.o stack_win.o main.o 
	$(CC) laba_win.o stack_win.o main.o -o lab
	
laba_win.o: laba_win.c
	$(CC) $(CFLAGS) $(STAND) laba_win.c
	
stack_win.o: stack_win.c
	$(CC) $(CFLAGS) $(STAND) stack_win.c 
	
main.o: main.c
	$(CC) $(CFLAGS) $(STAND) main.c 
else

all: output

output: laba_unix.o stack_unix.o main.o 
	$(CC) laba_unix.o stack_unix.o main.o -o lab 
	
laba_unix.o: laba_unix.c
	$(CC) $(CFLAGS) $(STAND) laba_unix.c 

stack_unix.o: stack_unix.c
	$(CC) $(CFLAGS) $(STAND) stack_unix.c 
	
main.o: main.c
	$(CC) $(CFLAGS) $(STAND) main.c 
	
endif
