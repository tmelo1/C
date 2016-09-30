/**
Lalit Varada, Ye Chan Kim, Tony Melo
lvarada1, ykim160, tmelo1
600.120 Spring 2016 Project 5
*/

#include <iostream>
#include <string>
#include <assert.h>
#include "battleship.h"
#include "checkers.h"
#include "game.h"

using namespace std;

int main(void)
{
	int game;

	cout << "CHOOSE A GAME:";
	cin >> game;

	if(game==1)
	{
		Battleship bt;

		int x;
		int y;
		char o;
		int size;

		string ship_names[5];
		ship_names[0] = "AIRCRAFT CARRIER";
		ship_names[1] = "BATTLESHIP";
		ship_names[2] = "CRUISER";
		ship_names[3] = "SUBMARINE";
		ship_names[4] = "DESTROYER";

		//adds the ships for Player1 and Player2
		for(int j = 1; j <= 2; j++)
			for(int i = 0; i <= 4; i++)
		{
			cout << "PLAYER " << j << " PLACE " << ship_names[i] << ":";
			string xyo;
			cin >> xyo;
			size = xyo.size();
			if(size!=3)
			{
				cout << "INVALID INPUT" << endl;
				return -1;
			}
			x = xyo.at(0) - '0';
			y = xyo.at(1) - '0';
			o = xyo.at(2);
			if(o=='h')
			bt.add_ship(make_pair(y,x),1,ship_names[i],j);
			if(o=='v')
			bt.add_ship(make_pair(y,x),0,ship_names[i],j);
		}
		//after the ships have been placed, the game starts
		cout << "BEGIN" << endl;

		GameResult result;
		//until there is a winner the game keeps going
		while(result == RESULT_KEEP_PLAYING || result == RESULT_INVALID)
		{
			string xy;
			bt.print();

			if(bt.get_turn() % 2 == 0)
			{
				cout << "PLAYER 1:";
			}
			if(bt.get_turn() % 2 == 1)
			{
				cout << "PLAYER 2:";
			}
			cin >> xy;
			size = xy.size();
			if(size!=2)
			{
				cout << "INVALID INPUT" << endl;
				result = RESULT_INVALID;
			}
			else
			{
				x = xy.at(0) - '0';
				y = xy.at(1) - '0';
				result = bt.attack_square(make_pair(y,x));
			}
		}

	}

	if(game==2)
	{
		Battleship mbt;

		int x;
		int y;
		char m;
		int d;
		char o;
		int size;

		string ship_names[5];
		ship_names[0] = "AIRCRAFT CARRIER";
		ship_names[1] = "BATTLESHIP";
		ship_names[2] = "CRUISER";
		ship_names[3] = "SUBMARINE";
		ship_names[4] = "DESTROYER";

		//adds the ships for Player1 and Player2
		for(int j = 1; j <= 2; j++)
			for(int i = 0; i <= 4; i++)
		{
			cout << "PLAYER " << j << " PLACE " << ship_names[i] << ":";
			string xyo;
			cin >> xyo;
			size = xyo.size();
			if(size!=3)
			{
				cout << "INVALID INPUT" << endl;
				return -1;
			}
			x = xyo.at(0) - '0';
			y = xyo.at(1) - '0';
			o = xyo.at(2);
			if(o=='h')
			mbt.add_ship(make_pair(y,x),1,ship_names[i],j);
			if(o=='v')
			mbt.add_ship(make_pair(y,x),0,ship_names[i],j);
		}
		//after the ships have been placed, the game starts
		cout << "BEGIN" << endl;

		GameResult result;
		while(result == RESULT_KEEP_PLAYING || result == RESULT_INVALID)
		{
			string input;
			mbt.print();

			if(mbt.get_turn() % 2 ==0)
			{
				cout << "PLAYER 1:";
			}
			if(mbt.get_turn() % 2 ==1)
			{
				cout << "PLAYER 2:";
			}
			cin >> input;
			size = input.size();
			if(size == 2)
			{
				x = input.at(0) - '0';
				y = input.at(1) - '0';
				result = mbt.attack_square(make_pair(y,x));
			}
			if(size == 4)
			{
				x = input.at(0) - '0';
				y = input.at(1) - '0';
				m = input.at(2);
				d = input.at(3) - '0';

				if(m=='u')
				result = mbt.move(make_pair(y,x),0,d);
				if(m=='r')
				result = mbt.move(make_pair(y,x),1,d);
				if(m=='d')
				result = mbt.move(make_pair(y,x),2,d);
				if(m=='l')
				result = mbt.move(make_pair(y,x),3,d);
			}
			if(size != 2 && size != 4)
			{
				cout << "INVALID INPUT" << endl;
				result = RESULT_INVALID;
			}
		}
	}
	if(game==3)
	{
		Checkers ch;

		int x;
		int y;
		int size;
		string move;
		string input;

		GameResult result;
		while(result == RESULT_KEEP_PLAYING || result == RESULT_INVALID)
		{

			ch.print();

			if(ch.get_turn() % 2 ==0)
			{
				cout << "PLAYER 1:";
			}
			if(ch.get_turn() % 2 ==1)
			{
				cout << "PLAYER 2:";
			}

			cin >> input;
			size = input.size();

			if(size != 4)
			{
				cout << "INVALID INPUT" << endl;
				result = RESULT_INVALID;
			}
			else
			{
				x = input.at(0) - '0';
				y = input.at(1) - '0';
				move = input.substr(2);
				cout << move << x << y << endl;
				if(move=="tl")
				result = ch.attack_square(make_pair(x,y),1);
				else if(move=="tr")
				result = ch.attack_square(make_pair(x,y),2);
				else if(move=="bl")
				result = ch.attack_square(make_pair(x,y),3);
				else if(move=="br")
				result = ch.attack_square(make_pair(x,y),4);

			}
		}
	}
	return 0;
}

