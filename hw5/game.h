#ifndef GAME_H
#define GAME_H

/*
 * Use this file as a *starting point*.  You may add more classes and other
 * definitions here.
 *
 * We have suggested a couple ideas (Board and Game) for base classes you can
 * use in your design.
 *
 * Implement derived types for the games in "battleship.h" and "tictactoe.h"
 *
 * You must use "enum GameResult" and "Coord" as defined here, and you must
 * implement derived types called BattleshipGame and TicTacToeGame, each with
 * a public attack_square member function, as you can see from reading
 * play_bs.cpp and play_ttt.cpp.
 */

#include <utility>
#include <cstdbool>
#include <map>

enum GameResult {
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

  virtual GameResult attack_square(Coord){return RESULT_INVALID;}
  void next_turn(){
    counter++;
  }
  int counter;		//where even is player1 and odd is player2

};

/*
//These gets inserted if attack_square hits an empty coord
class WhitePeg {
public:
	WhitePeg(int x, int y);
	    pos(std::make_pair(x,y)),maker('W') {};

	Coord pos;
	char marker;
};

//These gets inserted if attack_square hits a ship coord
class RedPeg {
public:
	RedPeg(int x, int y);
	   pos(std::make_pair(x, y)), maker('R') {};

	Coord pos;
	char marker;
};
*/
#endif
