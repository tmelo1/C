#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "game.h"
#include <utility>

typedef std::array<Coord, 5> Player;

class BattleshipGame : public Game {
 public:
  Board b1;
  Board b2;

  int p1ships = 5;
  int p2ships = 5;

  //constructor
 BattleshipGame(Player p1, Player p2): b1(10), b2(10)
    {
      //to fill in the boards, will exit if the ships overlap
      
      for(Coord& c: p1){
	if(b1.game_board.count(c) == 0){ b1.game_board[c] = 'O'; }
	else{ exit(1); }
      }
      
      for(Coord& c: p2){
	if(b2.game_board.count(c) == 0){ b2.game_board[c] = 'O'; }
	else{ exit(1); }
      }
      
    }

  GameResult attack_square(Coord c) {
    if(c.first >= 10 || c.second >= 10){ 
        next_turn();
        cout << "wrong coord" << endl;
        return RESULT_INVALID; 
    }
    //player 1's turn
    if(counter % 2 == 0) {
      //if it is a miss
      if(b2.game_board.count(c) == 0) {
          b2.game_board[c] = 'X';
          next_turn(); }
      //if it hits something
      if(b2.game_board.count(c) == 1) {
	//hits a place that it has already hit
	if(b2.game_board[c] == 'X') { 
          next_turn();
          cout << "already hit" << endl;
          return RESULT_INVALID; 
        }
	//hits a ship
	if(b2.game_board[c] == 'O') {
	  p2ships--;
	  b2.game_board[c] = 'X';
          next_turn();
	}
      }
    }
      //player 2's turn
    if(counter % 2 == 1) {
      //if it is a miss
      if(b1.game_board.count(c) == 0) { 
          b1.game_board[c] = 'X'; 
          next_turn();
      }
      //if it hits something
      if(b1.game_board.count(c) == 1) {
       	//hits a place that it has already hit
       	if(b1.game_board[c] == 'X'){ 
          next_turn();
          return RESULT_INVALID; 
        }
       	//hits a ship
       	if(b1.game_board[c] == 'O'){
      	  p1ships--;
      	  b1.game_board[c] = 'X';
          next_turn();
      	}
      }
    }
    if(p1ships == 0) {return RESULT_PLAYER2_WINS; }
    if(p2ships == 0) {return RESULT_PLAYER1_WINS; }
    return RESULT_KEEP_PLAYING;
  }
};
#endif
