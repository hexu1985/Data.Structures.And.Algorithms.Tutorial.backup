
RM = rm -f
CC = gcc
CFLAGS = -Wall -g -DNDEBUG -std=c99
INCLUDES = 
LDFLAGS = -lm
LDPATH =
VPATH = 

SOURCES = $(shell ls *.c)
PROGS = list_allocation

all: $(PROGS)
	@echo "PROGS = $(PROGS)" 

clean:
	$(RM) $(PROGS)

$(PROGS): $(SOURCES) $(LIB_SOURCES)
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) $^ $(LDFLAGS) $(LDPATH)
