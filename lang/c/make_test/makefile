CC = gcc

test: test.c tea.o
	$(CC) test.c tea.o -o test

tea: tea.c
	$(CC)  -c tea.c

clean:
	rm *.o test