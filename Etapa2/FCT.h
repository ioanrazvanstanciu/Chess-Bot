#ifndef _FCT_H_
#define _FCT_H_

#include <bits/stdc++.h>
#include <string.h>

#include <cstdlib>
#include <iostream>

#include "GAME.h"

//	structura unui punct de coordonate x, y:
struct point{
	int x,y;
};

//	declararea functiilor implementate:
void initial();
string move(string mutare, bool flag);
string generate_pawn_moves(string color);
point pawn_valid_move(int x, int y, string color);
bool isOntable(int x, int y);
string generate_rook_moves(string color);
point rook_valid_move(int x, int y, string color);
string generate_bishop_moves(string color);
point bishop_valid_move(int x, int y, string color);
string generate_knight_moves(string color);
point knight_valid_move(int x, int y, string color);
string generate_queen_moves(string color);
point queen_valid_move(int x, int y, string color);
string generate_king_moves(string color);
point king_valid_move(int x, int y, string color);

#endif