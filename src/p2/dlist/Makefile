SOURCE := dlist_test.c dlist.c dlist.h
FLAGS  := -Wall -Wextra -Werror -std=c99 -pedantic -gstabs

dlist.o: dlist.c
	gcc -c $(FLAGS) dlist.c

unit_test: dlist_test.c dlist.o 
	gcc -o test $(FLAGS) dlist_test.c dlist.o
	./test

memory_test: test
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./test

style:	
	indent -kr -brf -i2 -l80 -nut $(SOURCE)

clean:
	rm -f dlist.o test
