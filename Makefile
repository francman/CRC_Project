CC = gcc
CFLAGS = -Wall -ansi -std=c11 -pedantic-errors

main: main.o
	$(CC) -o main main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm main main.o