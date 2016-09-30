/**
Lalit Varada, Ye Chan Kim, Tony Melo
ykim 160, lvarada1, tmelo1
600.120 Spring 2016 Project 5
*/

#include "game.h"
#include <utility>
#include <iostream>
#include <set>
#include "checkers.h"

 Checkers::Checkers(): gboard(8) {
    for(int i = 0; i < 8; i++){ //vertical
      for(int j = 0; j < 8; j++){ //horizontal
	if(i%2 != j%2) { gboard.game_board[std::make_pair(i, j)] = ' '; }
	else {gboard.game_board[std::make_pair(i, j)] = '-';}
	if(i%2 != j%2 && i < 3){ gboard.game_board[std::make_pair(i, j)] = 'w'; } 
	if(i%2 != j%2 && i > 4){ gboard.game_board[std::make_pair(i, j)] = 'r'; } 
      }
    }
  }

  //tl:1 = top left
  //tr:2 = top right
  //bl:3 = bottom left
  //br:4 = bottom right

  
  GameResult Checkers::attack_square(Coord c, int k){

    if(c.first > 8 || c.second > 8 || c.first < 0 || c.second < 0 || k > 4 || k < 1) { return RESULT_INVALID; }
    int player = get_turn()%2 + 1;

    
    std::set<Coord> pieces = can_jump(player);
    if(pieces.size() == 0) {
      pieces = can_move(player);
    }
    if(pieces.count(c) == 0 && pieces.size() != 0) { return RESULT_INVALID; }
   
    int vertical = -1;
    int horizontal = 1;
    if(k > 2) { vertical *= -1; }
    if(k%2 == 1) { horizontal *= -1; }

    Coord next_pos = std::make_pair(c.first + vertical, c.second + horizontal);
    
    //for move
    if(gboard.game_board[next_pos] == ' ') {
      gboard.game_board[next_pos] = gboard.game_board[c];
      gboard.game_board[c] = ' ';

      //for crowning
      if(next_pos.first == 0 && gboard.game_board[next_pos] == 'r') {
	std::cout << "CROWNED" << std::endl;
	gboard.game_board[next_pos] = 'R';
      }

      if(next_pos.first == 7 && gboard.game_board[next_pos] == 'w') {
	std::cout << "CROWNED" << std::endl;
	gboard.game_board[next_pos] = 'W';
      }
      
      next_turn();
      return RESULT_KEEP_PLAYING;
    }
      
    //for jump
    if(gboard.game_board[next_pos] != ' ' && toupper(gboard.game_board[next_pos]) != toupper(gboard.game_board[c])) {
      GameResult gr = jump(c,k);
      if(gr == RESULT_KEEP_PLAYING) {
	next_turn();

	if(p1chips == 0) {
	  std::cout << "PLAYER 2 WON" << std::endl;
	  return RESULT_PLAYER2_WINS;
	}
	if(p2chips == 0) {
	  std::cout << "PLAYER 1 WON" << std::endl;
	  return RESULT_PLAYER1_WINS;
	}
	
	return gr;
      }
      
      return gr;      
    }

    //for stalemate
    std::set<Coord> p1 = can_jump(1);
    std::set<Coord> p2 = can_jump(2);
    if(p1.size() == 0) { p1 = can_jump(1); }
    if(p2.size() == 0) { p2 = can_jump(2); }
    if(p1.size() == 0 && p2.size() == 0) {
      std::cout << "STALEMATE" << std::endl;
      return RESULT_STALEMATE;
    }
    
    return RESULT_INVALID;
  }

  GameResult Checkers::jump(Coord c, int dir) {

    char mine = toupper(gboard.game_board[c]);
    
    //request for direction here
    std::string direction;
    while(dir > 4 || dir < 0) {
      std::cout << "Player " << (get_turn()%2+1) << " Enter Direction:";
      std::cin >> direction;
      std::cout << std::endl;

      if(direction.compare("tl") == 0) { dir = 1; }
      if(direction.compare("tr") == 0) { dir = 2; }
      if(direction.compare("bl") == 0) { dir = 3; }
      if(direction.compare("br") == 0) { dir = 4; }      
    }
    
    int vertical = -1;
    int horizontal = 1;
    if(dir < 5) {
      if(dir > 2) { vertical *= -1; }
      if(dir%2 == 1) { horizontal *= -1; }
    }
    Coord over = std::make_pair(c.first + vertical, c.second + horizontal);
    Coord des = std::make_pair(over.first + vertical, over.second + horizontal);

    //checks that this a valid jump
    if(gboard.game_board[over] == ' ') { return RESULT_INVALID; }
    if(gboard.game_board[des]  != ' ') { return RESULT_INVALID; }
    if(toupper(gboard.game_board[over]) == mine) { return RESULT_INVALID; }
      
    //does the jump
    gboard.game_board[over] = ' ';
    gboard.game_board[des] = gboard.game_board[c];

    //updates the count
    if(toupper(gboard.game_board[c]) == 'R') { p2chips--; }
    if(toupper(gboard.game_board[c]) == 'W') { p1chips--; }
    
    //finally clears the position of the old piece
    gboard.game_board[c] = ' ';


    //for crowning
    if(gboard.game_board[des] == 'r' && des.first == 0) {
      gboard.game_board[des] = 'R';
      std::cout << "CROWNING" << std::endl;
      return RESULT_KEEP_PLAYING;
    }

    if(gboard.game_board[des] == 'w' && des.first == 7) {
      gboard.game_board[des] = 'W';
      std::cout << "CROWNING" << std::endl;
      return RESULT_KEEP_PLAYING;
    }

    //sees if it can keep on jumping
    //if it can it does so, other wise it returns keep playing
    if(can_jump(get_turn()%2+1).count(des) == 1) { return jump(des, 5); } 
    return RESULT_KEEP_PLAYING;

  }
  

  //checks the pieces that the player can move
  std::set<Coord> Checkers::can_move(int player) {
    std::set<Coord> pieces;
    std::set<Coord> j_pieces;
    for(int i = 0; i < 8; i++) {
      for(int j = 0; j < 8; j++) {
	Coord pos = std::make_pair(i, j);
	if(gboard.game_board[pos] != ' ' || gboard.game_board[pos] != '-') {
	  //top left and right
	  if(gboard.game_board[std::make_pair(pos.first - 1, pos.second - 1)] == ' ' || gboard.game_board[std::make_pair(pos.first - 1, pos.second + 1)] == ' ') {
	    if(player == 1 && (gboard.game_board[pos] == 'r' || gboard.game_board[pos] == 'R') ) { pieces.insert(pos); }
	    if(player == 2 && gboard.game_board[pos] == 'W') { pieces.insert(pos); }
	  }
	    
	    //bottom left and right
	  if(gboard.game_board[std::make_pair(pos.first + 1, pos.second - 1)] == ' ' || gboard.game_board[std::make_pair(pos.first + 1, pos.second + 1)] == ' ') {
	    if(player == 2 && (gboard.game_board[pos] == 'w' || gboard.game_board[pos] == 'W') ) { pieces.insert(pos); }
	    if(player == 1 && gboard.game_board[pos] == 'R') { pieces.insert(pos); }
	  }
	}
      }
    }
    return pieces;
  }

  //checks the pieces that the player can jump
  std::set<Coord> Checkers::can_jump(int player) {
    std::set<Coord> j_pieces;
    for(int i = 0; i < 8; i++) {
      for(int j = 0; j < 8; j++) {
	Coord pos = std::make_pair(i, j);
	if(gboard.game_board[pos] != ' ' || gboard.game_board[pos] != '-') {	  
	  //top left jump
	  if(toupper(gboard.game_board[std::make_pair(pos.first - 1, pos.second - 1)]) != toupper(gboard.game_board[pos]) && gboard.game_board[std::make_pair(pos.first - 1, pos.second - 1)] != ' ' && gboard.game_board[std::make_pair(pos.first - 2, pos.second - 2)] == ' ') {
	    if(player == 1 && (gboard.game_board[pos] == 'r' || gboard.game_board[pos] == 'R') ) { j_pieces.insert(pos); }
	    if(player == 2 && gboard.game_board[pos] == 'W') { j_pieces.insert(pos); }
	  }
	  
	  //top right jump
	  if(toupper(gboard.game_board[std::make_pair(pos.first - 1, pos.second + 1)]) != toupper(gboard.game_board[pos]) && gboard.game_board[std::make_pair(pos.first - 1, pos.second + 1)] != ' ' && gboard.game_board[std::make_pair(pos.first - 2, pos.second + 2)] == ' ') {
	    if(player == 1 && (gboard.game_board[pos] == 'r' || gboard.game_board[pos] == 'R') ) { j_pieces.insert(pos); }
	    if(player == 2 && gboard.game_board[pos] == 'W') { j_pieces.insert(pos); }
	  }
	  
	  
	  //bottom left jump
	  if(toupper(gboard.game_board[std::make_pair(pos.first + 1, pos.second - 1)]) != toupper(gboard.game_board[pos]) && gboard.game_board[std::make_pair(pos.first + 1, pos.second - 1)] != ' ' && gboard.game_board[std::make_pair(pos.first + 2, pos.second - 2)] == ' ') {
	    if(player == 2 && (gboard.game_board[pos] == 'w' || gboard.game_board[pos] == 'W') ) { j_pieces.insert(pos); }
	    if(player == 1 && gboard.game_board[pos] == 'R') { j_pieces.insert(pos); }
	  }

	  //bottom right jump
	  if(toupper(gboard.game_board[std::make_pair(pos.first + 1, pos.second + 1)]) != toupper(gboard.game_board[pos]) && gboard.game_board[std::make_pair(pos.first + 1, pos.second + 1)] != ' ' && gboard.game_board[std::make_pair(pos.first + 2, pos.second + 2)] == ' ') {
	    if(player == 2 && (gboard.game_board[pos] == 'w' || gboard.game_board[pos] == 'W') ) { j_pieces.insert(pos); }
	    if(player == 1 && gboard.game_board[pos] == 'R') { j_pieces.insert(pos); }
	  }
	}
      }
    }
    return j_pieces;
  }

  //prints out the board
  void Checkers::print() {
    std::cout << "Board:" << std::endl;
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
	Coord c= std::make_pair(i,j);
	if(gboard.game_board.count(c) == 1){ std::cout << gboard.game_board[c] << " "; }
	else { std::cout << "- ";}
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }


