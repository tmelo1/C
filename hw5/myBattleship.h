#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <utility>
#include "game.h"
#include <array>

//This will be how we make the ships for each player
typedef std::array<Coord, 5> Player;

class BattleshipGame : public Game {
public:

    //Where the game is played
    Board battle_board1;

    Board battle_board2;

    //How many ships are downed
    int p1reds;

    int p2reds;

    //makes a board with two players, we can make the arrays in our executable
    BattleshipGame(Player p1, Player p2):
        battle_board1(10), battle_board2(10), p1reds(0), p2reds(0) {}

    void checkCoords(Player p1, Player p2) {

        //Quit if two ships are on the same spot or if we get invalid coords
        for (auto it = p1.begin(); it != p1.end(); ++it) {
            for (auto it2 = p2.begin(); it2 != p2.end(); ++it2) {
            if ((it -> first) >= 10 || (it -> second) >= 10) {
                exit(EXIT_FAILURE);
            } else if ((it2 -> first) >= 10 || (it2 -> second) >= 10) {
                exit(EXIT_FAILURE);
            }
        }
       // battle_board = Board(10), p1Reds(0), p2Reds(0) {}
        for (int i = 0; i < 5; i++) {
            battle_board1.game_board.insert(std::make_pair(p1[i], 'S'));
            battle_board2.game_board.insert(std::make_pair(p2[i], 'S'));
        }
    }


    GameResult attack_square(Coord c) { 
        GameResult state = RESULT_KEEP_PLAYING;
        if (c.first >= 10 || c.second >= 10) {   //check for invalid coordinates
            return RESULT_INVALID;
        } else {
            if (counter % 2 == 1) { //player 2's turn
                if (battle_board1.game_board[c] == 'W' || battle_board1.game_board[c] == 'R') {
                    state = RESULT_INVALID;
                }
                if (battle_board1.game_board[c] == 'S') {  //p1 has a ship here
                    battle_board1.game_board[c] = 'R';    //make it a red peg, 
                    battle_board1.p1Reds++;
                    if (battle_board1.p1Reds == 5) { //check if game is over
                        state = RESULT_PLAYER2_WINS;
                    }
                } else {
                    battle_board.game_board[c] = 'W';  //keep going with the game
                    state = RESULT_KEEP_PLAYING;
                    next_turn();
                }
            } else {
                if (battle_board2.game_board[c] == 'W' || battle_board2.game_board[c] == 'R') {
                    state = RESULT_INVALID;
                }
                if (battle_board2.game_board[c] == 'S') {
                    battle_board2.game_board[c] = 'R';
                    battle_board2.p2Reds++;
                    if (bsttle_board2.p2Reds == 5) {
                        state = RESULT_PLAYER1_WINS;
                    }
                } else {
                    battle_board2.game_board[c] = 'W';
                    state = RESULT_KEEP_PLAYING
                    next_turn();
                }
            }
            return state;
    }
};

#endif

