#pragma once
#include <string>
#include "move.h"
using std::string;

class Ataque:public Move
{
	string clase;
	int potencia;
public:
	Ataque(string,string,int,int,string,string,int);
	void afecto(int&,int&,int&,int&,int&,int&,int&,int&,string);
	string toString();	
};