CC=gcc
CFLAGS= -g -Wall -ansi -pedantic -O3
FILES=src/file.o src/game.o src/movement.o src/piece.o src/pile.o src/debug.o main.o
PROG=Chess

all:$(FILES)
	gcc $(CFLAGS) $(FILES) -o $(PROG)
file.o: file.c
	gcc -c $(CFLAGS) src/file.c
game.o: game.c
	gcc -c $(CFLAGS) src/game.c
movement.o: movement.c
	gcc -c $(CFLAGS) src/movement.c
piece.o: piece.c
	gcc -c $(CFLAGS) src/piece.c
pile.o: pile.c
	gcc -c $(CFLAGS) src/pile.c
debug.o: debug.c
	gcc -c $(CFLAGS) src/debug.c
 main.o: main.c
	gcc -c $(CFLAGS) main.c
