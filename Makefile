CC = gcc
CFLAGS = -Wall -ansi -std=c11 -pedantic-errors
DEPS = crc.h
OBJ = main.o crc.o

main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ 

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm main $(OBJ)