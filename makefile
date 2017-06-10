################################################################################
# NAME: makefile
# AUTHOR: Ethan D. Twardy
# DESCRIPTION: makefile for ciper
# CREATED: 06/08/17
# LAST EDITED: 06/08/17
################################################################################

P = cipher
OBJECTS= main.c cipher.c
CFLAGS = -Wall -O3 -I ./include/
LDLIBS=
CC = gcc

$(P): $(OBJECTS)

.PHONY: debug limited clean

CFLAGS_DEBUG = -g -O0 -Wall -I ./include/

debug:
	$(CC) $(CFLAGS_DEBUG) -o $(P) $(OBJECTS) $(LDLIBS)

# The limited rule compiles only the code that allows for encryption,
# and nothing else. 
CFLAGS_LIMITED = $(CFLAGS)
CFLAGS_LIMITED += -D CONFIG_LIMITED

limited:
	$(CC) $(CFLAGS_LIMITED) -o $(P) $(OBJECTS) $(LDLIBS)

clean:
	rm -rf *.c~
	rm -rf *.h~
	rm -rf makefile~