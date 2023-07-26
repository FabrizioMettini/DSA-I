FLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -gstabs

test: hashtable_sc_test.o hashtable_sc.o glist.o contact.o utils.o
	$(CC) -o $@ $^ $(FLAGS)

hashtable_sc_test.o: hashtable_sc_test.c hashtable.h contact.h
	$(CC) -c $< $(FLAGS)

hashtable_sc.o: hashtable_sc.c hashtable.h glist.h common.h
	$(CC) -c $< $(FLAGS)

glist.o: glist.c glist.h common.h
	$(CC) -c $< $(FLAGS)

contact.o: contact.c contact.h utils.h
	$(CC) -c $< $(FLAGS)

utils.o: utils.c utils.h
	$(CC) -c $< $(FLAGS)

memory_test: test
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all -s ./test

clean:
	rm -f *.o
	rm -f test

.PHONY = clean memory_test