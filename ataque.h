#pragma once
#include <string>
#include "move.h"
using std::string;

class Ataque:public Move
{
public:
	Ataque(string,string,int,int,string);
	void efecto(int&,int&,int&,int&,int&,int&,int&,int&,int);
	string toString();	
};