SOURCE := slists_test.c slists.c slists.h
FLAGS  := -Wall -Wextra -Werror -std=c99 -pedantic

test: slists_test.c
	gcc -c slists.c
	gcc -o test $(FLAGS) slists_test.c slists.o 

style:	
	indent -kr -brf -i2 -l80 -nut $(SOURCE)

clean:
	rm -f slists.o test