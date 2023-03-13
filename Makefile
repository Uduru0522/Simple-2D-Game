CC=gcc
INCDIR=src/include
LIBDIR=src/lib
LIBS=-lmingw32 -lSDL2main -lSDL2_image -lSDL2
CFLAGS=-I$(INCDIR) -L$(LIBDIR)

DEPS=icons.h
OBJS=main.o icons.o
TARGET=game

%.o: %.c $(DEPS)
icons.o: icons.h

all: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS) $(LIBS)
	./$(TARGET).exe

.PHONY: clean
clean:
	del $(TARGET).exe
	del *.o
