/*
 * ReversiGame.cpp
 *
 *  Created on: Jan 30, 2018
 *      Author: Mark 4
 */
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <string.h>

#include "ReversiGame.h"
#include <iostream>
using namespace std;

ReversiGame::ReversiGame() {
	// TODO Auto-generated constructor stub
	player1 = white;
	player2 = black;
}

ReversiGame::~ReversiGame() {
	// TODO Auto-generated destructor stub
}

void ReversiGame::initializeGameBoard(){
	this->board = new char*[8];
    for(int i = 0; i < 8; i++){
	    board[i] = new char[8];
    }
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j<8; j++){
		    board[i][j] = '#';
		}
	}
	board[4][4] = 'O';
	board[3][3] = 'O';
	board[3][4] = '@';
	board[4][3] = '@'; //Initial disc placement
	cout << "012345678" << endl;
	for (int i = 0; i < 8; i++) {
		cout << i+1;
		for (int j = 0; j<8; j++){
			cout << board[i][j];
		}
		cout << endl;
	}
}

void ReversiGame::nextMove(color player) {
	int row, column;
	if (player == white){
		cout << "Player 1's move. First enter your row, then below that enter your column. You can cheat, but don't. Don't put in a number above 8 or it won't work." << endl;
	}
	else{
		cout << "Player 2's move. First enter your row, then below that enter your column. You can cheat, but don't. Don't put in a number above 8 or it won't work." << endl;
	}
	string filler;
	getline(cin,filler);
	stringstream(filler) >> row;
	getline(cin,filler);
	stringstream(filler) >> column;
	column--;
	row--;
	if (player == black){
		board[row][column] = '@';
		for (int j = column+1; j<8; j++){
			if (board[row][j] == 'O'){
				continue;
			}
		    if (board[row][j] == '#'){
				break;
			}
			if (board[row][j] == '@'){
				for (int k = column+1; k<j; k++){
					board[row][k] = '@';
				}
				break;
			}
		}
		for (int j = column-1; j<8; j--){
			if (board[row][j] == 'O'){
				continue;
			}
		    if (board[row][j] == '#'){
				break;
			}
			if (board[row][j] == '@'){
				for (int k = column-1; k>j; k--){
					board[row][k] = '@';
				}
				break;
			}
		}
		for (int i = row+1; i<8; i++){
			if (board[i][column] == 'O'){
				continue;
			}
		    if (board[i][column] == '#'){
				break;
			}
			if (board[i][column] == '@'){
				for (int k = row+1; k<i; k++){
					board[k][column] = '@';
				}
				break;
			}
		}
		for (int i = row-1; i<8; i--){
			if (board[i][column] == 'O'){
				continue;
			}
		    if (board[i][column] == '#'){
				break;
			}
			if (board[i][column] == '@'){
				for (int k = row-1; k>i; k--){
					board[k][column] = '@';
				}
				break;
			}
		}
	}
	if (player == white){
		board[row][column] = 'O';
		for (int j = column+1; j<8; j++){
			if (board[row][j] == '@'){
				continue;
			}
		    if (board[row][j] == '#'){
				break;
			}
			if (board[row][j] == 'O'){
				for (int k = column+1; k<j; k++){
					board[row][k] = 'O';
				}
				break;
			}
		}
		for (int j = column-1; j<8; j--){
			if (board[row][j] == '@'){
				continue;
			}
		    if (board[row][j] == '#'){
				break;
			}
			if (board[row][j] == 'O'){
				for (int k = column-1; k>j; k--){
					board[row][k] = 'O';
				}
				break;
			}
		}
		for (int i = row+1; i<8; i++){
			if (board[i][column] == '@'){
				continue;
			}
		    if (board[i][column] == '#'){
				break;
			}
			if (board[i][column] == 'O'){
				for (int k = row+1; k<i; k++){
					board[k][column] = 'O';
				}
			}
		}
		for (int i = row-1; i<8; i--){
			if (board[i][column] == '@'){
				continue;
			}
		    if (board[i][column] == '#'){
				break;
			}
			if (board[i][column] == 'O'){
				for (int k = row-1; k>i; k--){
					board[k][column] = 'O';
				}
			}
		}
	}
	cout << "012345678" << endl;
	for (int i = 0; i < 8; i++) {
		cout << i+1;
		for (int j = 0; j<8; j++){
			cout << board[i][j];
		}
		cout << endl;
	}
}

int ReversiGame::getPlayer1Score() {
	int player1Count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j<8; j++){
			if (board[i][j] == 'O'){
				player1Count++;
			}
		}
	}
	return player1Count;
}

int ReversiGame::getPlayer2Score() {
	int player2Count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j<8; j++){
			if (board[i][j] == '@'){
				player2Count++;
			}
		}
	}
	return player2Count;
}

void ReversiGame::deallocateGameBoard(char ***board){
    for (int i = 0; i < 8; i++){
	    delete []board[i];}
    delete []board;
}


