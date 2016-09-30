CC = gcc
CONSERVATIVE_FLAGS = -std=c99 -pedantic -Wall -Wextra

hw2: dnasearch.o dnasearch.h hw2.o
	$(CC) $(CONSERVATIVE_FLAGS) -o hw2 hw2.o dnasearch.o dnasearch.h 
hw2.o: dnasearch.o
	$(CC) $(CONSERVATIVE_FLAGS) -c hw2.c
test_dnasearch.o: dnasearch.c dnasearch.h
	$(CC) $(CONSERVATIVE_FLAGS) -c test_dnasearch.c
dnasearch.o: dnasearch.h dnasearch.c
	$(CC) $(CONSERVATIVE_FLAGS) -c dnasearch.c
test_dnasearch: test_dnasearch.o dnasearch.o
	$(CC) -o test_dnasearch test_dnasearch.o dnasearch.o
clean:
	rm -f *.o test_dnasearch hw2 *.gcov
