CC = gcc
EXEC = prog


SRCDIR = src 
BINDIR = bin 
OBJDIR = obj


all:
	$(CC) -o bin/$(EXEC) src/main.c


run:
	./bin/prog