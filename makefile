all: main.o
	gcc -o prog main.o

main.o:
	gcc -c main.c
