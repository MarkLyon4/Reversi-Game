/*
 * ReversiGame.h
 *
 *  Created on: Jan 30, 2018
 *      Author: Mark 4
 */

#ifndef REVERSIGAME_H_
#define REVERSIGAME_H_

enum color { black, white };

class ReversiGame {
    public:
	    ReversiGame();
	    virtual ~ReversiGame();
		color player1;
	    color player2;
	    char **board;

        /* Initialize the 2-D array */
        void initializeGameBoard();

        /* A player makes his or her move */
        void nextMove(color player);

        /* Gets player 1's score */
        int getPlayer1Score();

        /* Gets player 2's score */
        int getPlayer2Score();

        /* Free the memory for the 2-D array */
        void deallocateGameBoard(char ***board);
};

#endif /* REVERSIGAME_H_ */
