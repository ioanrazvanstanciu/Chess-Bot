#include <bits/stdc++.h>
#include <string.h>

#include <cstdlib>
#include <iostream>

#include "FCT.h"

extern Game game;

int main() {
	// initializarea tablei de joc:
	game.update();
	// functie pentru citire/trimitere comenzi xboard:
	initial();
	
	return 0;
}