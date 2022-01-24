# Makefile

RM = rm -f
CC = gcc
CFLAGS = -Wall -g
INCLUDE = 
LDFLAGS = 
LDPATH = 

PROGS =	list_allocation list_reversal

.PHONY: all
all: $(PROGS)
	@echo "build OK!"

clean:
	@$(RM) $(PROGS) *.o
	@echo "clean OK!"

%.o:%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDE)

list_allocation: list_allocation.o list_functions.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LDPATH)

list_reversal: list_reversal.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LDPATH)


