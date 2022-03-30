#ifndef _PIESE_H_
#define _PIESE_H_

#include <bits/stdc++.h>

#include <cstdlib>
#include <iostream>

using namespace std;

//	superclasa pentru piese:
//	contine atributele generale ale unei piese;
class Piece{
	public:
		string name;
		string color;
	virtual string get_name(){return name;}
	virtual string get_color(){return color;}
};

//	clasa pentru Pion <- mosteneste piesa:
class Pawn : public Piece{
	public:
		Pawn(string color){
			name = "Pawn";
			this->color = color;
		}
		string get_name(){
			return name;
		}
		string get_color(){return color;}
};

//	clasa pentru Rege <- mosteneste piesa:
class King : public Piece{
	public:
		King(string color){
			name = "King";
			this->color = color;
		}
		string get_name(){
			return name;
		}
		string get_color(){return color;}
};

//	clasa pentru Regina <- mosteneste piesa:
class Queen : public Piece{
	public:
		Queen(string color){
			name = "Queen";
			this->color = color;
		}
		string get_name(){
			return name;
		}
		string get_color(){return color;}
};

//	clasa pentru Nebun <- mosteneste piesa:
class Bishop : public Piece{
	public:
		Bishop(string color){
			name = "Bishop";
			this->color = color;
		}
		string get_name(){
			return name;
		}
		string get_color(){return color;}
};

//	clasa pentru Tura <- mosteneste piesa:
class Rook : public Piece{
	public:
		Rook(string color){
			name = "Rook";
			this->color = color;
		}
		string get_name(){
			return name;
		}
		string get_color(){return color;}
};

//	clasa pentru Cal <- mosteneste piesa:
class Knight : public Piece{
	public:
		Knight(string color){
			name = "Knight";
			this->color = color;
		}
		string get_name(){
			return name;
		}
		string get_color(){return color;}
};

//	clasa pentru patratele goale <- mosteneste piesa:
class Empty : public Piece{
	public:
		Empty(){
			name = "Empty";
		}
		string get_name(){
			return name;
		}
		string get_color(){return color;}
};

#endif