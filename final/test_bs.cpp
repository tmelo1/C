/**
Lalit Varada Ye Chan Kim Tony Melo
tmelo1 lvarada1 ykim160
600.120 Spring 2016 Project 5
*/

#include "battleship.h"
#include <iostream>
#include <assert.h>


using namespace std;

//This game tests all bourders and player 2 wins
void game1()
{
	Battleship bt;

	//adds the ships for player 1
	bt.add_ship(make_pair(0,0),0,"AIRCRAFT CARRIER",1);
	bt.add_ship(make_pair(9,2),1,"BATTLESHIP",1);
	bt.add_ship(make_pair(0,4),1,"CRUISER",1);
	bt.add_ship(make_pair(0,9),0,"SUBMARINE",1);
	bt.add_ship(make_pair(4,2),1,"DESTROYER",1);

	//adds the ships for player 2
	bt.add_ship(make_pair(5,9),0,"AIRCRAFT CARRIER",2);
	bt.add_ship(make_pair(1,5),0,"BATTLESHIP",2);
	bt.add_ship(make_pair(7,1),1,"CRUISER",2);
	bt.add_ship(make_pair(5,6),1,"SUBMARINE",2);
	bt.add_ship(make_pair(5,0),0,"DESTROYER",2);

	bt.print();

	GameResult result = bt.attack_square(make_pair(5,0)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(12,13)); //P2 INVALID MOVE
	assert(result == RESULT_INVALID);

	result = bt.attack_square(make_pair(-1,-2)); //P2 INVALID MOVE
	assert(result == RESULT_INVALID);

	result = bt.attack_square(make_pair(0,0)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(5,1)); //P1 MISS
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(1,0)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(6,0)); //P1 HIT //SUNK DESTROYER
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(2,0)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(5,9)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(3,0)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(6,9)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(4,0)); //P2 HIT //SUNK AIRCRAFT CARRIER
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(7,9)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(0,9)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(8,9)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(1,9)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(9,9)); //P1 HIT //SUNK AIRCRAFT CARRIER
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(2,9)); //P2 HIT //SUNK SUBMARINE
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(1,5)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(4,2)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(2,5)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(4,3)); //P2 HIT //SUNK DESTROEYER
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(3,5)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(0,4)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(4,5)); //P1 HIT //SUNK BATTLESHIP
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(0,5)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(7,1)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(0,6)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(7,2)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(9,2)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(7,3)); //P1 HIT //SUNK CRUISER
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(9,3)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(5,6)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(9,4)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(5,7)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(9,5)); //P2 HIT //SUNK BATTLESHIP //PLAYER 2 WON
	assert(result == RESULT_PLAYER2_WINS);

	cout << "PASSED game 1" << endl;
}

//Tests all bourder cases and player 1 wins
void game2()
{
	Battleship bt;

	//adds the ships for player 1
	bt.add_ship(make_pair(0,0),0,"AIRCRAFT CARRIER",1);
	bt.add_ship(make_pair(9,2),1,"BATTLESHIP",1);
	bt.add_ship(make_pair(0,4),1,"CRUISER",1);
	bt.add_ship(make_pair(0,9),0,"SUBMARINE",1);
	bt.add_ship(make_pair(4,2),1,"DESTROYER",1);

	//adds the ships for player 2
	bt.add_ship(make_pair(5,9),0,"AIRCRAFT CARRIER",2);
	bt.add_ship(make_pair(1,5),0,"BATTLESHIP",2);
	bt.add_ship(make_pair(7,1),1,"CRUISER",2);
	bt.add_ship(make_pair(5,6),1,"SUBMARINE",2);
	bt.add_ship(make_pair(5,0),0,"DESTROYER",2);

	bt.print();

	GameResult result = bt.attack_square(make_pair(5,0)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(12,13)); //P2 INVALID MOVE
	assert(result == RESULT_INVALID);

	result = bt.attack_square(make_pair(-1,-2)); //P2 INVALID MOVE
	assert(result == RESULT_INVALID);

	result = bt.attack_square(make_pair(0,0)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(5,1)); //P1 MISS
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(1,0)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(6,0)); //P1 HIT //SUNK DESTROYER
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(2,0)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(5,9)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(3,0)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(6,9)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(4,0)); //P2 HIT //SUNK AIRCRAFT CARRIER
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(7,9)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(0,9)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(8,9)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(1,9)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(9,9)); //P1 HIT //SUNK AIRCRAFT CARRIER
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(2,9)); //P2 HIT //SUNK SUBMARINE
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(1,5)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(4,2)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(2,5)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(4,3)); //P2 HIT //SUNK DESTROEYER
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(3,5)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(0,4)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(4,5)); //P1 HIT //SUNK BATTLESHIP
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(0,5)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(7,1)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(0,6)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(7,2)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(9,2)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(7,3)); //P1 HIT //SUNK CRUISER
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(9,3)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(5,6)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(9,4)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(5,7)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(8,7)); //P2 MISS
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.attack_square(make_pair(5,8)); //P1 HIT //SUNK SUBMARINE //PLAYER 1 WON
	assert(result == RESULT_PLAYER1_WINS);

	cout << "PASSED game 2" << endl;
}

//Tests the moving function of the mobile battleship and all the bourder cases of move function
void game3()
{
	Battleship bt;

	//adds the ships for player 1
	bt.add_ship(make_pair(0,0),0,"AIRCRAFT CARRIER",1);
	bt.add_ship(make_pair(0,6),1,"BATTLESHIP",1);
	bt.add_ship(make_pair(2,8),0,"CRUISER",1);
	bt.add_ship(make_pair(3,2),1,"SUBMARINE",1);
	bt.add_ship(make_pair(6,4),0,"DESTROYER",1);

	//adds the ships for player 2
	bt.add_ship(make_pair(5,9),0,"AIRCRAFT CARRIER",2);
	bt.add_ship(make_pair(1,5),0,"BATTLESHIP",2);
	bt.add_ship(make_pair(7,1),1,"CRUISER",2);
	bt.add_ship(make_pair(5,6),1,"SUBMARINE",2);
	bt.add_ship(make_pair(5,0),0,"DESTROYER",2);

	bt.print();

	GameResult result = bt.attack_square(make_pair(5,0)); //P1 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.move(make_pair(6,0),3,1); //P2 INVALID MOVE //L move for vertical ship
	assert(result == RESULT_INVALID);

	result = bt.move(make_pair(6,0),0,4); //P2 INVALID MOVE //Move more than 3 steps
	assert(result == RESULT_INVALID);

	result = bt.move(make_pair(6,0),1,2); //P2 INVALID MOVE //R move for vertical ship
	assert(result == RESULT_INVALID);

	result = bt.move(make_pair(6,0),0,3); //P2 MOVE
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.move(make_pair(3,3),3,2); //P1 INVALID MOVE //Check if there is a ship there
	assert(result == RESULT_INVALID);

	result = bt.move(make_pair(3,3),0,1); //P1 INVALID MOVE //U of horizontal ship
	assert(result == RESULT_INVALID);

	result = bt.move(make_pair(3,3),2,2); //P1 INVALID MOVE //D of horizontal ship
	assert(result == RESULT_INVALID);

	result = bt.move(make_pair(3,3),1,1); //P1 MOVE
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.move(make_pair(7,1),3,2); //P2 INVALID MOVE //Check left border of board
	assert(result == RESULT_INVALID);

	result = bt.move(make_pair(7,1),3,1); //P2 MOVE
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.move(make_pair(2,8),0,2); //P1 INVALID MOVE //Check if there is a ship there
	assert(result == RESULT_INVALID);

	result = bt.move(make_pair(2,8),2,3); //P1 MOVE
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.move(make_pair(5,6),1,1); //P2 INVALID MOVE //Check right border of board
	assert(result == RESULT_INVALID);

	result = bt.move(make_pair(5,9),2,1); //P2 INVALID MOVE //Check bottom border of board
	assert(result == RESULT_INVALID);

	result = bt.attack_square(make_pair(6,4)); //P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.move(make_pair(0,0),0,1); //P1 INVALID MOVE //Check upper border of board
	assert(result == RESULT_INVALID);

	result = bt.attack_square(make_pair(3,0)); //P1 HIT //SUNK DESTROYER
	assert(result == RESULT_KEEP_PLAYING);

	cout << "PASSED game 3" << endl;

}

//Tests when incorrect coordinates are placed for the ships
void game4()
{
	Battleship bt;

	//adds the ships for player 1
	GameResult result = bt.add_ship(make_pair(0,0),0,"AIRCRAFT CARRIER",1);
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.add_ship(make_pair(-1,-2),1,"BATTLESHIP",1);  //Doesn't let input negative coord
	assert(result == RESULT_INVALID);

	result = bt.add_ship(make_pair(2,8),0,"CRUISER",1);
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.add_ship(make_pair(3,2),1,"SUBMARINE",1);
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.add_ship(make_pair(6,4),0,"DESTROYER",1);
	assert(result == RESULT_KEEP_PLAYING);

	//adds the ships for player 2
	result = bt.add_ship(make_pair(5,9),0,"AIRCRAFT CARRIER",2);
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.add_ship(make_pair(1,5),0,"BATTLESHIP",2);
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.add_ship(make_pair(11,12),1,"CRUISER",2); //Doesn't let input coord bigger than board
	assert(result == RESULT_INVALID);

	result = bt.add_ship(make_pair(5,6),1,"SUBMARINE",2);
	assert(result == RESULT_KEEP_PLAYING);

	result = bt.add_ship(make_pair(5,0),0,"DESTROYER",2);
	assert(result == RESULT_KEEP_PLAYING);

	cout << "PASSED game 4" << endl;

}

int main(void)
{
	game1();
	game2();
	game3();
	game4();

	return 0;
}
