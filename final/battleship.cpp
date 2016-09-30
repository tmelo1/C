#include "game.h"
#include <utility>
#include <map>
#include <vector>
#include <cstdbool>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "battleship.h"


 Ship::Ship(int o, Coord c, std::string s): orientation(o)
  {
    //orientation = o;
    head = c;
    name = s;
    if(name.compare("DESTROYER") == 0){ size = 2; }
    else if(name.compare("SUBMARINE") == 0){ size = 3; }
    else if(name.compare("CRUISER") == 0){ size = 3; }
    else if(name.compare("BATTLESHIP") == 0){ size = 4; }
    else if(name.compare("AIRCRAFT CARRIER") == 0){ size = 5; }

    if(o == 0){
      for(int i = 0; i < size; i++){ sections[std::make_pair(c.first + i, c.second)] = 'O'; }
    }

    if(o == 1){
      for(int i = 0; i < size; i++){ sections[std::make_pair(c.first, c.second + i)] = 'O'; }
    }
  }

  bool Ship::attack(Coord c) {
    bool hit = false;
    if(sections.count(c) == 1 && sections[c] == 'O'){
      hit = true;
      sections[c] = 'X';
    }

    int i = 0;
    for(auto s : sections) {
      if(s.second == 'X') { i++; }
    }
    if(i == size) { destroyed = true; }
    return hit;
  }


  GameResult Battleship::add_ship(Coord c, int o, std::string name, int player) {

    int size = 0;
    if(name.compare("DESTROYER") == 0){ size = 2; }
    else if(name.compare("SUBMARINE") == 0){ size = 3; }
    else if(name.compare("CRUISER") == 0){ size = 3; }
    else if(name.compare("BATTLESHIP") == 0){ size = 4; }
    else if(name.compare("AIRCRAFT CARRIER") == 0){ size = 5; }

    if((c.first  < 0) || c.second < 0) { return RESULT_INVALID; }
    if((o == 0 && c.first + size-1 > 9) || (o == 1 && c.second + size-1 > 9)) { return RESULT_INVALID; }

    for(auto& s : p[player-1]) {                //loops through the ships -- fix
	for(int i = 0; i < size; i++) {
	    Coord n;
	    if(o == 0) { n = std::make_pair(c.first + i, c.second); }
	    if(o == 1) { n = std::make_pair(c.first, c.second + i); }
	    if(s.check_ship(n)){ return RESULT_INVALID; }
	  }
      }
    p[player-1].push_back(Ship(o, c, name));
    return RESULT_KEEP_PLAYING;
  }


  GameResult Battleship::attack_square(Coord c) {
    if(c.first > 9 || c.second > 9 || c.first < 0 || c.second < 0) { return RESULT_INVALID; }
    //player 1
    if(get_turn()%2 == 0) {
      bool hit = false;
      for(unsigned i = 0; i < p[1].size(); i++) {
	//      std:string name;
	if(p[1][i].attack(c)) {
	  hit = true;
	  std::cout << "HIT " <<  std::endl;
	  //name = p[1][i].get_name();
	}
	if(hit == true) {
	  if(!p[1][i].alive()) {
	    std::cout << "SUNK " << p[1][i].get_name() << std::endl;
	    p[1].erase(p[1].begin() + i);
	  }
	  if(p[1].size() == 0) {
	    std::cout << "PLAYER 1 WON" << std::endl;
	    return RESULT_PLAYER1_WINS;
	  }
	}
      }
      if(!hit) { std::cout << "MISS" << std::endl; }
    }
    if(get_turn()%2 == 1) {
      bool hit = false;
      for(unsigned i = 0; i < p[0].size(); i++) {
	if(p[0][i].attack(c)) {
	  hit = true;
	  std::cout << "HIT"  << std::endl;
	}
	if(hit == true) {
	  if(!p[0][i].alive()) {
	    std::cout << "SUNK " << p[0][i].get_name() << std::endl;
	    p[0].erase(p[0].begin() + i);
	  }
	  if(p[0].size() == 0) {
	    std::cout << "PLAYER 2 WON" << std::endl;
	    return RESULT_PLAYER2_WINS;
	  }
	}
      }
      if(!hit) {
	std::cout << "MISS" << std::endl;
      }
    }

    next_turn();
    return RESULT_KEEP_PLAYING;
  }



  void Battleship::print() {
    //both player's boards
    for(int k = 0; k < 2; k++) {
      std::cout << "Player " << (k+1) << "'s board:" << std::endl;
      for(int i = 0; i < 10; i++) {
	for(int j = 0; j < 10; j++) {
	  Coord c = std::make_pair(i, j);
	  bool found = false;
	  for(Ship s: p[k]) {
	    if(s.check_ship(c)) {
	      found = true;
	      std::cout << s.get_section(c) << " ";
	    }
	  }
	  if(!found) { std::cout << ". "; }
	}
	std::cout << std::endl;
      }
      std::cout << std::endl;
    }
  }

  GameResult Battleship::move(Coord c, int dir, int steps) {
    if(dir < 0 || dir > 4 || steps < 1 || steps > 3) { return RESULT_INVALID; }

    //gets the turn and has int to mark position of the ship
    int play = get_turn()%2;
    int o_s = -1;

    //lookes for the ship
    for(unsigned i = 0; i < p[play].size(); i++) {
      if(p[play][i].check_ship(c)) {
	o_s = i;
      }
    }

    //checks if the ship was found
    if(o_s < 0) { return RESULT_INVALID; }
    Ship old_s = p[play][o_s];

    //makes sure the movment is allowed in ships direction
    if(dir%2 != old_s.get_orientation()) { return RESULT_INVALID; }

    //delets the old ship so that a new ship can be added
    p[play].erase(p[play].begin() + o_s);

    //makes it such that you don't need to use two loops
    int v_s = 0;
    int h_s = 0;
    if(dir%2 == 0) {
      v_s = steps;
      if(dir == 0) { v_s = -1*v_s; }
    }
    if(dir%2 == 1) {
      h_s = steps;
      if(dir == 3) { h_s = -1*h_s; }
    }

    //the head of the new ship
    Coord n_head = std::make_pair(old_s.get_head().first + v_s, old_s.get_head().second + h_s);

    //addes the new ship
    GameResult gr = add_ship(n_head, old_s.get_orientation(), old_s.get_name(), get_turn()%2 + 1);

    //checks if the movement worked
    if(gr == RESULT_INVALID) {
      p[play].push_back(old_s);
      return gr;
    }

    //changes it to a one step movement
    if(v_s != 0) { v_s = 1; }
    if(h_s != 0) { h_s = 1; }

    //adds the attacks
    Coord o_h = old_s.get_head();
    for(int i = 0; i < old_s.get_size(); i++) {
      if(old_s.get_section(o_h) == 'X') { p[play][p[play].size() - 1].attack(n_head) ;}
      o_h    = std::make_pair(o_h.first + v_s,    o_h.second + h_s);
      n_head = std::make_pair(n_head.first + v_s, n_head.second + h_s);
    }

    //since move worked we can go to the next turn
    next_turn();
    return RESULT_KEEP_PLAYING;
  }
