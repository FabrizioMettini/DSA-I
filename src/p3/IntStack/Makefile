FLAGS = -Wall -Wextra -Werror -std=c99
CC 	  = gcc

test: stack_test.o stack.o IntArray.o
	$(CC) -o $@ $^ $(FLAGS)

stack_test.o: stack_test.c stack.h IntArray.h
	$(CC) -c $< $(FLAGS)

stack.o: stack.c stack.h IntArray.h
	$(CC) -c $< $(FLAGS)

IntArray.o: IntArray.c IntArray.h
	$(CC) -c $< $(FLAGS)

clean:
	rm -f *.o
	rm -f test

.PHONY = clean