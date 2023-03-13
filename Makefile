CC=gcc
INCDIR=src/include
LIBDIR=src/lib
LIBS=-lmingw32 -lSDL2main -lSDL2_image -lSDL2
CFLAGS=-I$(INCDIR) -L$(LIBDIR)

DEPS=icon.h
OBJS=main.o icon.o
TARGET=game

%.o: %.c $(DEPS)
icon.o: icon.h

all: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS) $(LIBS)
	./$(TARGET).exe

.PHONY: clean
clean:
	del $(TARGET).exe
	del *.o
