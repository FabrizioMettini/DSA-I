FLAGS = -Wall -Wextra -Werror -std=c99

test: bstree_test.o bstree.o
	$(CC) -o $@ $^ $(FLAGS)

bstree_test.o: bstree_test.c bstree.h
	$(CC) -c $< $(FLAGS)

bstree.o: bstree.c bstree.h
	$(CC) -c $< $(FLAGS)

clean:
	rm -f *.o
	rm -f test

.PHONY = clean