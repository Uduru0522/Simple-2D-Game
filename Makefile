CC=gcc
INCDIR=src/include
LIBDIR=src/lib
LIBS=-lmingw32 -lSDL2main -lSDL2_image -lSDL2
CFLAGS=-I$(INCDIR) -L$(LIBDIR)

DEPS=sprite.h
OBJS=main.o sprite.o
TARGET=game

%.o: %.c $(DEPS)
sprite.o: sprite.h

all: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS) $(LIBS)
	./$(TARGET).exe

.PHONY: clean
clean:
	del $(TARGET).exe
	del *.o
