################################################################################
# NAME: makefile
# AUTHOR: Ethan D. Twardy
# DESCRIPTION: makefile for ciper
# CREATED: 06/08/17
# LAST EDITED: 06/08/17
################################################################################

P = cipher
OBJECTS= main.c cipher.c
CFLAGS = -Wall -O3
LDLIBS=
CC = gcc

$(P): $(OBJECTS)

.PHONY: debug clean

CFLAGS_DEBUG = -g -O0 -Wall

debug:
	$(CC) $(CFLAGS_DEBUG) -o $(P) $(OBJECTS) $(LDLIBS)

clean:
	rm -rf *.c~
	rm -rf *.h~
	rm -rf makefile~