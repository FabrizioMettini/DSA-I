FLAGS = -Wall -Wextra -Werror -std=c99

test: btree_test.o btree.o
	$(CC) -o $@ $^ $(FLAGS)

btree_test.o: btree_test.c btree.h
	$(CC) -c $< $(FLAGS)

btree.o: btree.c btree.h
	$(CC) -c $< $(FLAGS)

clean:
	rm -f *.o
	rm -f test

.PHONY = clean