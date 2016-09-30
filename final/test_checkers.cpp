/**
Ye Chan Kim, Lalit Varada, Tony Melo
600.120 Spring 2016 Project 5
JHEDs - ykim160, lvarada1, tmelo1
*/

#include "game.h"
#include "checkers.h"
#include <iostream>
#include <assert.h>

using namespace std;


void game1() {
    Checkers ck1;
    ck1.print();
    GameResult result;
    result = ck1.attack_square(make_pair(-1, 0), 5);
    assert(result == RESULT_INVALID); //invalid p1

    result = ck1.attack_square(make_pair(9, 1), 2);
    assert(result == RESULT_INVALID); //invalid p1

    result = ck1.attack_square(make_pair(5,6), 2);
    assert(result == RESULT_KEEP_PLAYING); //p1 moves
    ck1.print();

    result = ck1.attack_square(make_pair(2, 1), 3);
    assert(result == RESULT_KEEP_PLAYING); //p2 moves
    ck1.print();

    result = ck1.attack_square(make_pair(5, 2), 1); //p1
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(3, 0), 4); //p2
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(6, 3), 1); //p1
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(2, 7), 3); //p2
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(7, 2), 2);
    assert(result == RESULT_KEEP_PLAYING); //p1
    ck1.print();

    result = ck1.attack_square(make_pair(1, 1), 4); //just testin
    assert(result == RESULT_INVALID);
    ck1.print();

    result = ck1.attack_square(make_pair(1, 0), 4);
    assert(result == RESULT_KEEP_PLAYING); //p2
    ck1.print();

    result = ck1.attack_square(make_pair(5, 4), 2); //p1
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(3, 6), 3); //p2
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(7, 4), 3);
    assert(result == RESULT_INVALID);
    ck1.print();

    result = ck1.attack_square(make_pair(7, 4), 1); //p1
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(7, 2), 2); //p2
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(6, 5), 1); //p1
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(2, 1), 3); //p2
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(4, 7), 1); //p1
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(3, 0), 4); //p2
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(5, 0), 2); //p1
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(2, 5), 4); //p2
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(4, 1), 1); //p1
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(4, 7), 3); //p2
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(6, 7), 1); //p1
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(1, 6), 3); //p2
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(7, 6), 1); //p1
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(5, 2), 4); //p2
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(6, 5), 2); //p1
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(6, 3), 3); //p2
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(6, 1), 2); //p1
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(7, 2), 2); //p2
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(5, 6), 2); //p1
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(6, 3), 1); //p2
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(7, 0), 2); //p1
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(2, 3), 4); //p2
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(4, 5), 1); //p1
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(1, 4), 3); //p2
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(6, 1), 2); //p1
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(4, 1), 4); //p2
    assert(result == RESULT_KEEP_PLAYING); 
    ck1.print();

    result = ck1.attack_square(make_pair(3, 0), 2); //p1
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(1, 2), 3); //p2
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(4, 7), 1); //p1
    assert(result == RESULT_KEEP_PLAYING);
    ck1.print();

    result = ck1.attack_square(make_pair(2, 5), 4); //p2
    assert(result == RESULT_PLAYER2_WINS);
    ck1.print();
}



int main(void) {
   game1();
}
