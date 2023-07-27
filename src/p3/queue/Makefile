FLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -g

test: queue_test.o queue.o gdlist.o
	$(CC) -o $@ $^ $(FLAGS)

queue_test.o: queue_test.c queue.h gdlist.h common.h
	$(CC) -c $< $(FLAGS)

queue.o: queue.c queue.h 
	$(CC) -c $< $(FLAGS)

gdlist.o: gdlist.c gdlist.h common.h
	$(CC) -c $< $(FLAGS)

memory_test: test
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./test

clean:
	rm -f *.o
	rm -f test

.PHONY = clean memory_test