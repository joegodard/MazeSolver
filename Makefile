CC = gcc
CFLAGS = -lncurses -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: clean maze

clean:
	rm maze

maze:
	$(CC) $(SOURCES) $(CFLAGS) -o $@