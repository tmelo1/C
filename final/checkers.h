/**
Lalit Varada, Ye Chan Kim, Tony Melo
ykim 160, lvarada1, tmelo1
600.120 Spring 2016 Project 5
*/

#ifndef CHECKERS_H
#define CHECKERS_H

#include "game.h"
#include <utility>
#include <iostream>
#include <set>

class Checkers: public Game{
 private:
  int p1chips = 12;
  int p2chips = 12;
  Board gboard;

 public:
  Checkers();

  GameResult attack_square(Coord c, int k);

  GameResult jump(Coord c, int dir);

  std::set<Coord> can_move(int player);

  std::set<Coord> can_jump(int player);

  void print();
};


#endif
