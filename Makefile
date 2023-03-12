CC=gcc
INCDIR=src/include
LIBDIR=src/lib
LIBS=-lmingw32 -lSDL2main -lSDL2
CFLAGS=-I$(INCDIR) -L$(LIBDIR)

DEPS=icons.h
OBJS=main.o icons.o

%.o: %.c $(DEPS)
icons.o: icons.h

all: $(OBJS)
	$(CC) -o game $(OBJS) $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	del game.exe
	del *.o
