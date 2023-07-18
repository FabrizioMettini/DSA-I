FLAGS = -Wall -Wextra -Werror -std=c99

program: glist_test.o glist.o contact.o
	$(CC) -o $@ $^ $(FLAGS)

glist_test.o: glist_test.c glist.h contact.h
	$(CC) -c $< $(FLAGS)

glist.o: glist.c glist.h
	$(CC) -c $< $(FLAGS)

contact.o: contact.c contact.h
	$(CC) -c $< $(FLAGS)

clean:
	rm *.o
	rm program

.PHONY = clean