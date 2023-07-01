FLAGS := -Wall -Wextra -Werror -std=c99 -pedantic

compile:
	gcc $(FLAGS) IntArray_test.c IntArray.c -o test

style:	
	indent -kr -brf -i2 -l80 -nut IntArray_test.c IntArray.c IntArray.h