#ifndef _GAME_H_
#define _GAME_H_

#include <bits/stdc++.h>

#include <cstdlib>
#include <iostream>

#include "PIESE.h"

using namespace std;

//	structura pentru patratele tablei de joc:
struct square {
	Piece piece;		//	piesa de pe un patrat
};

//	Clasa jocului:
class Game {	
	public:
		//	declararea tablei de joc:
		square Board[9][9];

	//	functie ce initializeaza piesele cat si
	//	valorile pe tabla de joc:
	void update() {
		//	declararea pieselor de culoare alba:
		Rook W_Rook("White");
		Bishop W_Bishop("White");
		Knight W_Knight("White");
		King W_King("White");
		Queen W_Queen("White");
		Pawn W_Pawn("White");

		//	declararea pieselor de culoare neagra:
		Rook B_Rook("Black");
		Bishop B_Bishop("Black");
		Knight B_Knight("Black");
		King B_King("Black");
		Queen B_Queen("Black");
		Pawn B_Pawn("Black");

		//	declararea piesei empty ce va tine locul
		//	patratelor goale de pe tabla de joc:
		Empty empty;

		//	ordonarea pieselor albe pe tabla de joc:
		Board[8][1].piece = W_Rook;
		Board[8][2].piece = W_Knight;
		Board[8][3].piece = W_Bishop;
		Board[8][4].piece = W_Queen;
		Board[8][5].piece = W_King;
		Board[8][6].piece = W_Bishop;
		Board[8][7].piece = W_Knight;
		Board[8][8].piece = W_Rook;

		//	ordonarea pionilor albi pe tabla de joc:
		for(int i = 1; i<=8;i++)
			Board[7][i].piece = W_Pawn;
		
		// 	ordonarea pieselor negre pe tabla de joc:
		Board[1][1].piece = B_Rook;
		Board[1][2].piece = B_Knight;
		Board[1][3].piece = B_Bishop;
		Board[1][4].piece = B_Queen;
		Board[1][5].piece = B_King;
		Board[1][6].piece = B_Bishop;
		Board[1][7].piece = B_Knight;
		Board[1][8].piece = B_Rook;
		
		//	ordonarea pionilor negri pe tabla de joc:
		for(int i = 1; i<=8;i++)
			Board[2][i].piece = B_Pawn;
		
		//	atribuirea patratelor goale pe tabla de joc:
		for(int i=3; i<=6;i++)
			for(int j = 1; j<=8;j++)
				Board[i][j].piece = empty;
	}
};

#endif