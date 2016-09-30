CC = g++
CONSERVATIVE_FLAGS = -Wall -Wextra -pedantic -std=c++11
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

hw4b_test: hw4b_test.o
	$(CC) $(CFLAGS) -o hw4b_test hw4b_test.o

hw4b_test.o: hw4b_test.cpp
	$(CC) $(CFLAGS) -c hw4b_test.cpp

hw4b: hw4b.o
	$(CC) $(CFLAGS) -o hw4b hw4b.o

hw4b.o: hw4b.cpp
	$(CC) $(CFLAGS) -c hw4b.cpp

hw4a: hw4a.o
	$(CC) $(CFLAGS) -o hw4a hw4a.o

hw4a_test: hw4a_test.o
	$(CC) $(CFLAGS) -o hw4a_test hw4a_test.o

hw4a_test.o: hw4a_test.cpp
	$(CC) $(CFLAGS) -c hw4a_test.cpp

hw4a.o: hw4a.cpp
	$(CC) $(CFLAGS) -c hw4a.cpp
