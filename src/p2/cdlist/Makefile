SOURCE := cdlist_test.c cdlist.c cdlist.h
FLAGS  := -Wall -Wextra -Werror -std=c99 -pedantic -gstabs

cdlist.o: cdlist.c
	gcc -c $(FLAGS) cdlist.c

unit_test: cdlist_test.c cdlist.o 
	gcc -o test $(FLAGS) cdlist_test.c cdlist.o
	./test

memory_test: test
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./test

style:	
	indent -kr -brf -i2 -l80 -nut $(SOURCE)

clean:
	rm -f cdlist.o test
