CC=gcc
INCDIR=src/include
LIBDIR=src/lib
LIBS=-lmingw32 -lSDL2main -lSDL2
CFLAGS=-I$(INCDIR) -L$(LIBDIR)

DEPS=icon.h
OBJS=main.o icon.o

%.o: %.c $(DEPS)
icon.o: icon.h

all: $(OBJS)
	$(CC) -o game $(OBJS) $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	del game.exe
	del *.o
