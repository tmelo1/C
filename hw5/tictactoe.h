#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "game.h"
#include <utility>

class TicTacToeGame : public Game {
public:
  Board tic_board;

  //constructor
  TicTacToeGame(): tic_board(3) { }

  //plays the turn
  GameResult attack_square(Coord c){
    if(c.first >= 3 || c.second >= 3){ return RESULT_INVALID; }
    if(tic_board.game_board.count(c) != 0){ return RESULT_INVALID; }
    else {
      char piece = 'O';
      if(counter%2 == 1){ piece = 'X'; }
      tic_board.game_board[c] = piece;
      next_turn();
    }
    GameResult k = win();

    if(counter >= 9){ return RESULT_STALEMATE; }
    return k;
  }

  GameResult win(){
    char winner = 'w';
    //columns and rows
    for (int i = 0; i < 3; i++){

      //columns
      Coord a = std::make_pair(i, 0);
      Coord b = std::make_pair(i, 1);
      Coord c = std::make_pair(i, 2);
      if((tic_board.game_board.count(a) == 1 && tic_board.game_board.count(b) == 1 && tic_board.game_board.count(c) == 1) && (tic_board.game_board[a] == tic_board.game_board[b] && tic_board.game_board[b] == tic_board.game_board[c]))
      {winner = tic_board.game_board[a]; }

      //rows
      a = std::make_pair(0, i);
      b = std::make_pair(1, i);
      c = std::make_pair(2, i);
      if((tic_board.game_board.count(a) == 1 && tic_board.game_board.count(b) == 1 && tic_board.game_board.count(c) == 1) && (tic_board.game_board[a] == tic_board.game_board[b] && tic_board.game_board[b] == tic_board.game_board[c]))
      {winner = tic_board.game_board[a]; }

      //diagonals
      a = std::make_pair(0, 0);
      b = std::make_pair(1, 1);
      c = std::make_pair(2, 2);
      if((tic_board.game_board.count(a) == 1 && tic_board.game_board.count(b) == 1 && tic_board.game_board.count(c) == 1) && (tic_board.game_board[a] == tic_board.game_board[b] && tic_board.game_board[b] == tic_board.game_board[c]))
      {winner = tic_board.game_board[a]; }

      a = std::make_pair(0, 2);
      b = std::make_pair(1, 1);
      c = std::make_pair(2, 0);
      if((tic_board.game_board.count(a) == 1 && tic_board.game_board.count(b) == 1 && tic_board.game_board.count(c) == 1) && (tic_board.game_board[a] == tic_board.game_board[b] && tic_board.game_board[b] == tic_board.game_board[c]))
      {winner = tic_board.game_board[a]; }
    }
      //checking if someone won
      if(winner == 'O'){ return RESULT_PLAYER1_WINS; }
      else if(winner == 'X'){ return RESULT_PLAYER2_WINS; }
      else { return RESULT_KEEP_PLAYING; }
  }

};
#endif
