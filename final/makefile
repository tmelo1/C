#Tony Melo Lalit Varada Ye Chan Kim
#tmelo1 lvarada1 ykim160
#600.120 Spring 2016 Project 5


CXX = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CXXFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

all: allgames

allgames: allgames.o checkers.o battleship.o
	$(CXX) -o allgames allgames.o checkers.o battleship.o $(CXXFLAGS)

checkers.o: checkers.cpp checkers.h
	$(CXX) -c checkers.cpp $(CXXFLAGS)

test_checkers: test_checkers.o
	$(CXX) -o test_checkers test_checkers.o checkers.o $(CXXFLAGS)

test_checkers.o: test_checkers.cpp checkers.h
	$(CXX) -c test_checkers.cpp $(CXXFLAGS)

test_bs: test_bs.o
	$(CXX) -o test_bs test_bs.o battleship.o $(CXXFLAGS)

test_bs.o: test_bs.cpp battleship.h
	$(CXX) -c test_bs.cpp $(CXXFLAGS)

allgames.o: allgames.cpp checkers.o game.h
	$(CXX) -c allgames.cpp $(CXXFLAGS)

battleship.o: battleship.cpp game.h
	$(CXX) -c battleship.cpp $(CXXFLAGS)


clean:
	rm -f *.o allgames *~ *.gch
