SOURCE := slist_test.c slist.c slist.h
FLAGS  := -Wall -Wextra -Werror -std=c99 -pedantic

compile:
	gcc -c slist.c

test: slist.o
	gcc -o test $(FLAGS) slist_test.c slist.o 

style:	
	indent -kr -brf -i2 -l80 -nut $(SOURCE)