# Makefile

RM = rm -f
CC = gcc
CFLAGS = -Wall -g
INCLUDE = 
LDFLAGS = 
LDPATH = 

PROGS =	list_reversal list_insertion_sort

.PHONY: all
all: $(PROGS)
	@echo "build OK!"

clean:
	@$(RM) $(PROGS) *.o
	@echo "clean OK!"

%.o:%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDE)

list_reversal: list_reversal.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LDPATH)

list_insertion_sort: list_insertion_sort.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LDPATH)


