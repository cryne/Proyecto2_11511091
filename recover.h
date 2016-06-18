#pragma once
#include <string>
#include "move.h"
using std::string;

class Recover:public Move
{
public:
	Recover(string,string,int,int,string);
	void efecto(int&,int&,int&,int&,int&,int&,int&,int&,int);
	string toString();	
};