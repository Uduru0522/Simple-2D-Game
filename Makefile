all:
	gcc -I src/include -L src/lib -o game main.c -lmingw32 -lSDL2main -lSDL2
