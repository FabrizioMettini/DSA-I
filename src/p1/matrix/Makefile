SOURCE := matrix_test.c matrix_bi.c matrix_uni.c matrix.h
FLAGS  := -Wall -Wextra -Werror -std=c99 -pedantic

compile:
	gcc $(FLAGS) matrix_test.c matrix_bi.c -o test

style:	
	indent -kr -brf -i2 -l80 -nut $(SOURCE)