#include "battleship.h"
#include <iostream>
#include <array>
#include "game.h"
#include <cassert>

using namespace std;

void game1()
{

	array<Coord, 5> player1_ships = {{
		make_pair(2, 2),
		make_pair(4, 4),
		make_pair(5, 5),
		make_pair(6, 6),
		make_pair(8, 8)
	}};
	array<Coord, 5> player2_ships = {{
		make_pair(2, 2),
		make_pair(4, 4),
		make_pair(5, 5),
		make_pair(6, 6),
		make_pair(8, 8)
	}};
	BattleshipGame bsg(player1_ships, player2_ships);
	
	GameResult result = bsg.attack_square(make_pair(2, 2)); // P1 HIT
	assert(result == RESULT_KEEP_PLAYING);
	
	result = bsg.attack_square(make_pair(2, 2)); // P2 HIT
	assert(result == RESULT_KEEP_PLAYING);
	
	// oops, already an X on this square
	result = bsg.attack_square(make_pair(2, 2)); // P1 invalid move
	assert(result == RESULT_INVALID);
	
	// note: an invalid move doesn't count as a turn; still player 1's turn
	
	result = bsg.attack_square(make_pair(4, 4)); // P1 HIT
	assert(result == RESULT_KEEP_PLAYING);
	
	result = bsg.attack_square(make_pair(4, 4)); // P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bsg.attack_square(make_pair(5, 5)); // P1 HIT
	assert(result == RESULT_KEEP_PLAYING);
	
	result = bsg.attack_square(make_pair(5, 5)); // P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bsg.attack_square(make_pair(6, 6)); // P1 HIT
	assert(result == RESULT_KEEP_PLAYING);
	
	result = bsg.attack_square(make_pair(6, 6)); // P2 HIT
	assert(result == RESULT_KEEP_PLAYING);

	result = bsg.attack_square(make_pair(8, 8)); // P1 HIT
	assert(result == RESULT_PLAYER1_WINS);

	cout << "PASSED game 1" << endl;
}

int main(void)
{
	game1();
	// TODO: add more games as test
	return 0;
}
