FLAGS = -Wall -Wextra -Werror -std=c99

test: stack_test.o stack.o glist.o contact.o
	$(CC) -o $@ $^ $(FLAGS)

stack_test.o: stack_test.c stack.h contact.h
	$(CC) -c $< $(FLAGS)

stack.o: stack.c stack.h
	$(CC) -c $< $(FLAGS)

glist.o: glist.c glist.h
	$(CC) -c $< $(FLAGS)

contact.o: contact.c contact.h
	$(CC) -c $< $(FLAGS)	

clean:
	rm -f *.o
	rm -f test

.PHONY = clean