//============================================================================
// Name        : New.cpp
// Author      : Mark Lyon
// Version     :
// Copyright   : Your copyright notice
// Description : Reversi Game
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>

#include "ReversiGame.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	ReversiGame game;
	int player1Score, player2Score;
	int number_rounds;
	cout << "Welcome to Reversi! Player 1 will be white and Player 2 will be black." << endl;
	cout << "In this variation of Reversi, only horizontal and vertical outflankings score points. No diagonals." << endl;
	cout << "Game will be limited by rounds. Set the number of rounds players have to place disks." << endl;
	string filler;
	getline(cin,filler);
	stringstream(filler) >> number_rounds;
	game.initializeGameBoard();
	for (int i = 0; i < number_rounds; i++){
		game.nextMove(game.player1);
		game.nextMove(game.player2);
	}
	player1Score = game.getPlayer1Score();
	player2Score = game.getPlayer2Score();
	cout << "The score is Player 1: " << player1Score << " and Player 2: " << player2Score << endl;
	game.deallocateGameBoard(&game.board);
    return 0;
}
