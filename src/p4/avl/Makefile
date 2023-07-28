FLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -g

test: avl_test.o avl.o
	$(CC) -o $@ $^ $(FLAGS)

avl_test.o: avl_test.c avl.h
	$(CC) -c $< $(FLAGS)

avl.o: avl.c avl.h
	$(CC) -c $< $(FLAGS)

memory_test: test
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./test

clean:
	rm -f *.o
	rm -f test

.PHONY = clean memory_test