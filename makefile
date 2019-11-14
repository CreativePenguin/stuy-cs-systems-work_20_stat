ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif


all: main.o
	$(CC) -o prog main.o

main.o: main.c
	$(CC) -c main.c

run:
	./prog

clean:
	rm *.o prog demo
