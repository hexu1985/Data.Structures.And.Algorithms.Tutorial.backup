# Makefile

RM = rm -f
CC = gcc
CFLAGS = -Wall -g
INCLUDE = 
LDFLAGS = 
LDPATH = 

PROGS =	circular_lists list_allocation

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

circular_lists: circular_lists.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LDPATH)

