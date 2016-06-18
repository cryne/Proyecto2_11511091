#pragma once
#include <string>
#include "move.h"
using std::string;

class Proteccion:public Move
{
public:
	Proteccion(string,string,int,int,string);
	void efecto(int&,int&,int&,int&,int&,int&,int&,int&,int);
	string toString();	
};