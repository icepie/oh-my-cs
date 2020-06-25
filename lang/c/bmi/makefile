CC = gcc

all: main

main: main.c bmi.o 
	$(CC) main.c bmi.o -o bmi

bmi: bmi.c
	$(CC) -c bmi.c

clean:
	rm -rf *.o bmi