FLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -gstabs

test: bheap_test.o bheap.o
	$(CC) -o $@ $^ $(FLAGS)

bheap_test.o: bheap_test.c bheap.h
	$(CC) -c $< $(FLAGS)

bheap.o: bheap.c bheap.h
	$(CC) -c $< $(FLAGS)

memory_test: test
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all -s ./test

clean:
	rm -f *.o
	rm -f test

.PHONY = clean memory_test