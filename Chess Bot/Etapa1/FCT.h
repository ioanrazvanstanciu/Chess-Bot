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

#endif