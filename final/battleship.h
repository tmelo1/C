/**
Lalit Varada, Ye Chan Kim, Tony Melo
tmelo1, lvarada1, ykim160
600.120 Spring 2016 Project 5
*/

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "game.h"
#include <utility>
#include <map>
#include <vector>
#include <cstdbool>
#include <iostream>
#include <string>
#include <stdlib.h>

class Ship{

private:
  std::string name;
  Coord head;
  bool destroyed = false;
  int size;
  std::map<Coord, char> sections;
  int orientation; //if orientation = 0 it means vertical
                   //if orientation = 1 it means horizontal


public:

 Ship(int o, Coord c, std::string s);

 std::string get_name() { return name; }

  bool attack(Coord c);

  //check if a coordinate is part of the ship
  bool check_ship(Coord c){
    if(sections.count(c) == 1){ return true; }
    return false;
  }

  char get_section(Coord c){
    if(sections.count(c) == 1) { return sections[c]; }
    return 'N';
  }

  //check if the ship is alive
  bool alive() { return !destroyed; }

  int get_orientation() { return orientation; }

  Coord get_head() { return head; }

  int get_size() { return size; }

};





//Start of the Battleship Class
class Battleship : public Game
{
 private:

  std::vector<Ship> p[2];

 public:

  Battleship() { }

  GameResult add_ship(Coord c, int o, std::string name, int player);

  GameResult attack_square(Coord c);

  void print();

  GameResult move(Coord c, int dir, int steps);

};


#endif
