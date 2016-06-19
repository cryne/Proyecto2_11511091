#pragma once
#include <string>
#include "move.h"
using std::string;

class Recover:public Move
{
public:
	Recover(string,string,int,int,string);
	int efecto(int,int,int,int,int);
	string toString();	
};