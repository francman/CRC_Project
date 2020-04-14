# Copyright (c) 2020 Frank Manu

# This source code is licensed under MIT license fount in the
# LICENSE file in the root directory of this source tree

# The script is created in fulfillment of required coursework
# from the Coding and Information Theory class at UMass Lowell
# EECE 5480 - Spring 2020

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