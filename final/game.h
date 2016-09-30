/**
Lalit Varada, Ye Chan Kim, Tony Melo
lvarada1, ykim160, tmelo1
600.120 Spring 2016 Project 5
*/

#ifndef GAME_H
#define GAME_H

#include <utility>
#include <cstdbool>
#include <map>

enum GameResult{
	RESULT_KEEP_PLAYING, // turn was valid and game is not over yet
	RESULT_INVALID,      // turn was invalid; e.g. attacked square
	                     // was attacked previously
	RESULT_STALEMATE,    // game over, neither player wins
	RESULT_PLAYER1_WINS, // game over, player 1 wins
	RESULT_PLAYER2_WINS  // game over, player 2 wins
};

typedef std::pair<int, int> Coord;

class Board {
public:
  Board(int s): size(s) {}

  int size;
  std::map<Coord,char> game_board;
};

class Game {
public:
  Game() : counter(0) {}

  virtual GameResult attack_square(Coord) {return RESULT_INVALID;}

  void next_turn(){
    counter++;
  }

  virtual void print() {}

  int get_turn(){ return counter; }

 private:
  int counter;		//where even is player1 and odd is player2

};

#endif

